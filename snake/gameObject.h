#ifndef SNAKE_GAMEOBJECT_H
#define SNAKE_GAMEOBJECT_H

#include "declarations.h"

class gameObject
{
public:
    explicit gameObject(float _x = 0, float _y = 0, Color _color = RAYWHITE)
        : posX(_x), posY(_y), color(_color)
    {
    }

    virtual void move(Vector2 &pos)
    {
        posX = pos.x;
        posY = pos.y;
    }

    virtual float getX() const
    {
        return posX;
    }

    virtual float getY() const
    {
        return posY;
    }

    virtual bool isSnake()
    {
        return false;
    }

    virtual void draw() = 0;

private:
    float posX;
    float posY;
    Color color;
};

#endif //SNAKE_GAMEOBJECT_H
