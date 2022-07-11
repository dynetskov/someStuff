#include "food.h"

namespace Food
{
    food::food(float _x, float _y, float _size, Color _color)
            : gameObject(_x, _y, _color), size(_size)
    {
    }

    void food::draw()
    {
        DrawRectangleLinesEx(Rectangle{posX, posY, size, size}, 3.0f, color);
    }

    /*void food::move(Vector2 &pos)
    {
        posX = pos.x;
        posY = pos.y;
    }*/

    /*float food::getX() const
    {
        return posX;
    }*/

    /*float food::getY() const
    {
        return posY;
    }*/

    float food::getSize() const
    {
        return size;
    }

} // Food