#include "map.h"

map::map(float _x, float _y, Vector2 _size, Color _color)
        : gameObject(_x, _y, _color), size(_size)
{
}

map::~map()
{
    std::cout << "map deleted" << std::endl;
}

Vector2 map::getMapSize() const
{
    return size;
}

void map::draw()
{
    DrawRectangleLinesEx(Rectangle{posX, posY, size.x, size.y}, 5.0f, color);
}

bool map::mapCollision(gameObject &snake, mapParameter par, direction dir)
{
    if (!snake.isSnake())
        throw std::logic_error("Invalid object type in method mapCollision. Should be Snake type");

    //if (CheckCollisionRecs(Rectangle{posX, posY, size.x, size.y},
    //                       Rectangle{snake.getX(), snake.getY(), snake.getSize(), snake.getSize()}))
    Rectangle mapRec{posX, posY, size.x, size.y};
    Vector2 point;
    Vector2 offset;
    Vector2 prev;

    switch (dir)
    {
        case DIR_UP:
            point.x = snake.getX();
            point.y = snake.getY();
            offset = Vector2{0, size.y-10};
            prev = Vector2{0, snake.getSize()};
            break;
        case DIR_DOWN:
            point.x = snake.getX();
            point.y = snake.getY()+snake.getSize();
            offset = Vector2{0, -(size.y-10)};
            break;
        case DIR_LEFT:
            point.x = snake.getX();
            point.y = snake.getY();
            offset = Vector2{size.x-10, 0};
            break;
        case DIR_RIGHT:
            point.x = snake.getX()+snake.getSize();
            point.y = snake.getY();
            offset = Vector2{-(size.x-10), 0};
            break;
    }

    if (!CheckCollisionPointRec(point, mapRec))
    {
        if (par == BLOCKED)
        {
            return true;
        }

        //offset.y -= snake.getSize();
        //snake.move(prev);
        snake.move(offset);
    }

    return false;
}