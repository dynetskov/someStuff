#include "map.h"
#include "snake.h"

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

    Rectangle mapRec{posX, posY, size.x, size.y};
    Vector2 point;
    Vector2 newPos;

    point.x = snake.getX();
    point.y = snake.getY();

    switch (dir)
    {
        case DIR_UP:

            newPos = Vector2{0, size.y-10};
            break;
        case DIR_DOWN:
            point.y += snake.getSize();
            newPos = Vector2{0, -(size.y-10)};
            break;
        case DIR_LEFT:
            newPos = Vector2{size.x-10, 0};
            break;
        case DIR_RIGHT:
            point.x += snake.getSize();
            newPos = Vector2{-(size.x-10), 0};
            break;
    }

    if (!CheckCollisionPointRec(point, mapRec))
    {
        if (par == BLOCKED)
            return true;

        auto cast_snake = dynamic_cast<Snake::snake*>(&snake);

        cast_snake->sideMove(newPos);
    }

    return false;
}