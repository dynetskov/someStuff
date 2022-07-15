#include "snake.h"

namespace Snake //class snake
{
    snake::snake(float _x, float _y, float _size, Color _color)
            : gameObject(_x/2-_size/2, _y/2-_size/2, _color), size{_size}
    {
        body.emplace_back(size, color, posX, posY);
    }

    snake::~snake()
    {
        std::cout << "Snake Deleted" << std::endl;
    }

    bool snake::isSnake()
    {
        return true;
    }

    void snake::draw()
    {
        for (auto &el: body)
            el.draw();
    }

    void snake::move(Vector2 direction)
    {
        Vector2 next;
        Vector2 prev;

        next.x = direction.x+body.front().getX();
        next.y = direction.y+body.front().getY();

        for (auto &el: body)
        {
            prev.x = el.getX();
            prev.y = el.getY();
            el.move(next);

            next.x = prev.x;
            next.y = prev.y;
        }

        posX = body.front().getX();
        posY = body.front().getY();
    }

    void snake::moveOffset(Vector2 offset)
    {
        for (auto &el: body)
            el.moveOffset(offset);
    }

    void snake::sideMove(Vector2 offset)
    {
        posX += offset.x;
        posY += offset.y;

        body.front().move(Vector2{posX, posY});
    }

    void snake::add(direction dir)
    {
        if (body.begin() == body.end())
            return;

        auto it = body.end();
        it--;

        float x = it->getX();
        float y = it->getY();

        if (it != body.begin())
        {
            std::cout << "if" << std::endl;
            it--;

            x += x-it->getX();
            y += y-it->getY();
        } else
        {
            std::cout << "else" << std::endl;
            switch (dir)
            {
                case DIR_UP:
                    y += size;
                    break;
                case DIR_DOWN:
                    y -= size;
                    break;
                case DIR_LEFT:
                    x += size;
                    break;
                case DIR_RIGHT:
                    x -= size;
                    break;
            }
        }

        body.emplace_back(size, color, x, y);
    }

    float snake::getSize() const
    {
        return size;
    }

    bool snake::collision(const gameObject &obj, std::list<bodyPart>::iterator &it)
    {
        //auto head = body.begin();

        return CheckCollisionRecs(Rectangle{it->getX(), it->getY(), size, size},
                                  Rectangle{obj.getX(), obj.getY(), obj.getSize(), obj.getSize()});
    }

    bool snake::headCollision(const gameObject &obj)
    {
        auto head = body.begin();

        return collision(obj, head);
    }

    bool snake::bodyCollision(const gameObject &obj)
    {
        auto it = body.begin();

        while (it != body.end())
        {
            if (collision(obj, it))
                return true;

            it++;
        }

        return false;
    }
}


namespace Snake //class body_part
{
    bodyPart::bodyPart(float &_size, Color &_color, float _x, float _y)
            : gameObject(_x, _y, _color), size(_size)
    {
    }

    bodyPart::~bodyPart()
    {
        std::cout << "Body part Deleted" << std::endl;
    }

    void bodyPart::draw()
    {
        DrawRectangleLinesEx(Rectangle{posX, posY, size, size}, 3, color);
    }

    float bodyPart::getSize() const
    {
        return size;
    }
}