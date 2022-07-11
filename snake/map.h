#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include "declarations.h"
#include "gameObject.h"

class map : public gameObject
{
public:
    map(float _x, float _y, Vector2 _size = Vector2{500, 500}, Color _color = RAYWHITE);
    ~map();

    void draw() override;
    Vector2 getMapSize() const;

private:
    Vector2 size;

    float getSize() const override
    {
        return 0;
    }
};

#endif //SNAKE_MAP_H
