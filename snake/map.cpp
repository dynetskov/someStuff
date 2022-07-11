#include "map.h"

map::map(float _x, float _y, Vector2 _size, Color _color)
    : gameObject(_x, _y, _color), size(_size)
{
}

map::~map()
{
    std::cout << "map deleted" << std::endl;
}

Vector2 map::getSize()
{
    return size;
}

void map::draw()
{
    DrawRectangleLinesEx(Rectangle{posX, posY, size.x, size.y}, 5.0f, color);
}