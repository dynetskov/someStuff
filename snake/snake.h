#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "declarations.h"
#include "food.h"

namespace Snake
{
    class bodyPart : public gameObject
    {
    public:
        bodyPart(float &_size, Color &_color, float _x, float _y);
        ~bodyPart();

        void draw() override;
        float getSize() const override;

    private:
        float size;
    };

    class snake : public gameObject
    {
    public:
        snake(float _x, float _y, float _size = 25.0f, Color _color = RAYWHITE);
        ~snake();

        bool isSnake() override;

        void draw() override;
        void move(Vector2 direction) override;
        void add(direction dir);
        float getSize() const override;

        bool checkFoodCollision(const Food::food &food, std::list<bodyPart>::iterator &it);
        bool foodHeadCollision(const Food::food &food);
        bool foodBodyCollision(const Food::food &food);

    private:
        std::list<bodyPart> body;
        float size;
    };
}

#endif //SNAKE_SNAKE_H
