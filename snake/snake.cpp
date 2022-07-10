#include "snake.h"

namespace Snake //class snake
{
    snake::snake(int _x, int _y, float _size, Color _color)
            : size{_size}, color{_color}
    {
        body.emplace_back(size, color, static_cast<float>(_x)/2-size/2, static_cast<float>(_y)/2-size/2);
    }

    snake::~snake()
    {
        std::cout << "Snake Deleted" << std::endl;
    }

    void snake::draw()
    {
        for (auto &el: body)
            el.draw();
    }

    void snake::move(Vector2 &direction)
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

    }
}


namespace Snake //class body_part
{
    bodyPart::bodyPart(float &_size, Color &_color, float _x, float _y)
            : size(_size), color(_color), posX(_x), posY(_y)
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

    void bodyPart::move(Vector2 &pos)
    {
        posX = pos.x;
        posY = pos.y;
    }

    float bodyPart::getX() const
    {
        return posX;
    }

    float bodyPart::getY() const
    {
        return posY;
    }
}