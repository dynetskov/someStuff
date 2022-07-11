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

    float food::getSize() const
    {
        return size;
    }

    bool food::isFood()
    {
        return true;
    }

} // Food