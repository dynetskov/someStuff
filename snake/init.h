#ifndef SNAKE_INIT_H
#define SNAKE_INIT_H

#include "declarations.h"
#include "snake.h"
#include "food.h"

void initGame();
inline void drawMap(int w, int h, float line, Color color);
void checkKeys(float &size, Vector2 &speed, bool &canMove, direction &dir);

#endif //SNAKE_INIT_H
