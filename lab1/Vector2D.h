#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <iostream>
#include <cmath>
using namespace std;

class Vector2D {
 public:

  Vector2D();
  Vector2D(float _x, float _y);
  Vector2D(Vector2D &otherVector);
  ~Vector2D();

  void view();
  void setX(float value);
  void setY(float value);
  float getX();
  float getY();
  void reverse();
  void rotate(float angle);
  float normal();
  Vector2D normalize();

  Vector2D &operator+=(Vector2D &otherVector);
  Vector2D &operator-=(Vector2D &otherVector);
  Vector2D &operator*=(float value);
  Vector2D &operator/=(float value);
  Vector2D &operator=(Vector2D const &otherVector);
  float &operator[](int index);

 private:

  float x;
  float y;

  friend Vector2D operator+(Vector2D &lhs, Vector2D &rhs);
  friend Vector2D operator-(Vector2D &lhs, Vector2D &rhs);
  friend float operator*(Vector2D &lhs, Vector2D &rhs);
};

#endif
