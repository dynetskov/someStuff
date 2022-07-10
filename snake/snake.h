#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "declarations.h"
#include "food.h"

namespace Snake
{
    class bodyPart
    {
    public:
        bodyPart(float &_size, Color &_color, float _x, float _y);
        ~bodyPart();

        void draw();
        void move(Vector2 &pos);

        float getX() const;
        float getY() const;

    private:
        float posX;
        float posY;
        Color &color;
        float &size;
    };

    class snake
    {
    public:
        snake(int _x, int _y, float _size = 25.0f, Color _color = RAYWHITE);
        ~snake();

        void draw();
        void move(Vector2 &direction);
        void add(direction dir);

    private:
        std::list<bodyPart> body;
        Color color;
        float size;
    };
}

#endif //SNAKE_SNAKE_H
