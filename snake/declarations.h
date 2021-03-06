#ifndef SNAKE_DECLARATIONS_H
#define SNAKE_DECLARATIONS_H

#include <iostream>
#include <raylib.h>
#include <vector>
#include <list>
#include <memory>
#include <random>
#include <exception>

enum direction
{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
};

enum mapParameter
{
    BLOCKED,
    UNBLOCKED,
};

#endif //SNAKE_DECLARATIONS_H
