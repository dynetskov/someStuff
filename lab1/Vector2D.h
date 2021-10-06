#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <iostream>
using namespace std;

class Vector2D {
 public:

  Vector2D();
  Vector2D(float _x, float _y);
  Vector2D(Vector2D &otherVector);

  void view();
  void reverse();

  Vector2D &operator+=(Vector2D &otherVector);
  Vector2D &operator-=(Vector2D &otherVector);
  Vector2D &operator*=(float value);
  Vector2D &operator/=(float value);
  Vector2D &operator=(Vector2D const &otherVector);

 private:

  float x;
  float y;
  friend Vector2D operator+(Vector2D &lhs, Vector2D &rhs);
  friend Vector2D operator-(Vector2D &lhs, Vector2D &rhs);
  friend float operator*(Vector2D &lhs, Vector2D &rhs);
  //friend Vector2D operator*(Vector2D &otherVector, float value);
};

#endif
