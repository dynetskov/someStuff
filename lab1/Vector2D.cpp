#include "Vector2D.h"

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
  cout << x << " " << y << endl;
}

void Vector2D::reverse()
{
  x = -x;
  y = -y;
}

Vector2D &Vector2D::operator+=(Vector2D &otherVector)
{
  x += otherVector.x;
  y += otherVector.y;
  return *this;
}

Vector2D &Vector2D::operator-=(Vector2D &otherVector)
{
  x -= otherVector.x;
  y -= otherVector.y;
  return *this;
}

Vector2D operator+(Vector2D &lhs, Vector2D &rhs)
{
  Vector2D result(lhs.x, lhs.y);
  result += rhs;
  return result;
}

Vector2D operator-(Vector2D &lhs, Vector2D &rhs)
{
  Vector2D result(lhs.x, lhs.y);
  result -= rhs;
  return result;
}

float operator*(Vector2D &lhs, Vector2D &rhs)
{
  return (lhs.x * rhs.x + lhs.y * rhs.y);
}

/*Vector2D operator*(Vector2D &otherVector, float value)
{
  Vector2D result(otherVector.x * value, otherVector.y * value);
  return result;
}*/

Vector2D &Vector2D::operator*=(float value)
{
  x *= value;
  y *= value;
  return *this;
}

Vector2D &Vector2D::operator/=(float value)
{
  x /= value;
  y /= value;
  return *this;
}