#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include "declarations.h"

namespace Food
{
    class food
    {
    public:
        explicit food(float _x = 0, float _y = 0, float _size = 25.0f, Color _color = RAYWHITE);
        void draw();
        void move(Vector2 &pos);


        float getX() const;
        float getY() const;
        float getSize() const;

    private:
        float posX;
        float posY;
        float size;
        Color color;
    };
} // Food

#endif //SNAKE_FOOD_H
