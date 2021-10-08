#include "Vector2D.h"

Vector2D::Vector2D() :
    x(3), y(4)
{

}

Vector2D::Vector2D(float _x, float _y) :
    x(_x), y(_y)
{

}

Vector2D::Vector2D(Vector2D &otherVector) :
    x(otherVector.x), y(otherVector.y)
{

}

Vector2D::~Vector2D()
{

}

void Vector2D::view()
{
  cout << x << " " << y << endl;
}

void Vector2D::setX(float value)
{
  x = value;
}

void Vector2D::setY(float value)
{
  y = value;
}

float Vector2D::getX()
{
  return x;
}
float Vector2D::getY()
{
  return y;
}

void Vector2D::reverse()
{
  x = -x;
  y = -y;
}

void Vector2D::rotate(float angle)
{
  float xRot = x*cos(angle)-y*sin(angle);
  float yRot = x*sin(angle)+y*cos(angle);

  x = xRot;
  y = yRot;
}

float Vector2D::normal()
{
  return sqrt(x*x+y*y);
}

Vector2D Vector2D::normalize()
{
  float value = normal();
  float xNorm = x/value;
  float yNorm = y/value;

  Vector2D normalizedVector(xNorm, yNorm);

  return normalizedVector;
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
  return (lhs.x*rhs.x+lhs.y*rhs.y);
}


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

Vector2D &Vector2D::operator=(Vector2D const &otherVector)
{
  x = otherVector.x;
  y = otherVector.y;
  return *this;
}

float &Vector2D::operator[](int index)
{
  switch (index)
    {
      case 0:
        return x;
      case 1:
        return y;
    }
}