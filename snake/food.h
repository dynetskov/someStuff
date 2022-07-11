#ifndef SNAKE_FOOD_H
#define SNAKE_FOOD_H

#include "declarations.h"
#include "gameObject.h"

namespace Food
{
    class food : public gameObject
    {
    public:
        explicit food(float _x = 0, float _y = 0, float _size = 25.0f, Color _color = RAYWHITE);
        ~food()
        {
            std::cout << "food deleted" << std::endl;
        }
        food(const food &obj) = delete;

        void draw() override;
        //void move(Vector2 &pos);


        //float getX() const;
        //float getY() const;
        float getSize() const;

    private:
        //float posX;
        //float posY;
        float size;
        //Color color;
    };
} // Food

#endif //SNAKE_FOOD_H
