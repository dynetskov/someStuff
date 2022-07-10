#include "food.h"

namespace Food
{
    food::food(float _x, float _y, float _size, Color _color)
            : posX(_x), posY(_y), size(_size), color(_color)
    {
    }

    void food::draw()
    {
        DrawRectangleLinesEx(Rectangle{posX, posY, size, size}, 3.0f, color);
    }

    float food::getX() const
    {
        return posX;
    }

    float food::getY() const
    {
        return posY;
    }

} // Food