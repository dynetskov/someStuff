#include "food.h"
#include "snake.h"

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

    void food::replace(gameObject &snake, const map &map)
    {
        if (!snake.isSnake())
            return;


        auto cast_snake = dynamic_cast<Snake::snake*>(&snake);

        float new_x;
        float new_y;

        const Vector2 &mapSize = map.getMapSize();

        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<> dist_x(0, mapSize.x/size-1);
        std::uniform_int_distribution<> dist_y(0, mapSize.y/size-1);

        do
        {
            new_x = dist_x(eng)*size+map.getX()+5;
            new_y = dist_y(eng)*size+map.getY()+5;
            move(Vector2{new_x, new_y});
        } while (cast_snake->foodBodyCollision(*this));
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