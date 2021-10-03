#include "Vector2D.h"
#include <iostream>
using namespace std;

Vector2D::Vector2D() :
    x(3), y(4)
{

}

Vector2D::Vector2D(float _x, float _y) :
    x(_x), y(_y)
{

}

Vector2D::Vector2D(Vector2D &otherVector)
{
  x = (otherVector.x);
  y = (otherVector.y);
}

void Vector2D::view()
{

}