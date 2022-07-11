#ifndef SNAKE_INIT_H
#define SNAKE_INIT_H

#include "declarations.h"
#include "snake.h"
#include "food.h"
#include "map.h"

void initGame();
void checkKeys(float &size, Vector2 &speed, bool &canMove, direction &dir);

#endif //SNAKE_INIT_H
