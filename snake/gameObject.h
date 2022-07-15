#ifndef SNAKE_GAMEOBJECT_H
#define SNAKE_GAMEOBJECT_H

#include "declarations.h"

class gameObject
{
public:
    virtual void draw() = 0;
    virtual float getSize() const = 0;

    explicit gameObject(float _x = 0, float _y = 0, Color _color = RAYWHITE)
        : posX(_x), posY(_y), color(_color)
    {
    }

    virtual void move(Vector2 pos)
    {
        posX = pos.x;
        posY = pos.y;
    }

    virtual void moveOffset(Vector2 offset)
    {
        posX += offset.x;
        posY += offset.y;
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

    virtual bool isFood()
    {
        return false;
    }

protected:
    float posX;
    float posY;
    Color color;
};

#endif //SNAKE_GAMEOBJECT_H
