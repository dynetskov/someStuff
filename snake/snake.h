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
        //void move(Vector2 &pos);

        //float getX() const;
        //float getY() const;

    private:
        //float posX;
        //float posY;
        //Color &color;
        float &size;
    };

    class snake : public gameObject
    {
    public:
        snake(int _x, int _y, float _size = 25.0f, Color _color = RAYWHITE);
        ~snake();

        bool isSnake() override;

        void draw() override;
        void move(Vector2 &direction) override;
        void add(direction dir);

        bool checkFoodCollision(const Food::food &food, std::list<bodyPart>::iterator &it);
        bool foodHeadCollision(const Food::food &food);
        bool foodBodyCollision(const Food::food &food);

    private:
        std::list<bodyPart> body;
        float size;
    };
}

#endif //SNAKE_SNAKE_H
