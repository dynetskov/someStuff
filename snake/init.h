#ifndef SNAKE_INIT_H
#define SNAKE_INIT_H

#include "declarations.h"
#include "snake.h"

enum direction
{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
};

void initGame();
void drawMap(int w, int h, float line, Color color);
void checkDir(float &size, Vector2 &speed, bool &canMove);

#endif //SNAKE_INIT_H
