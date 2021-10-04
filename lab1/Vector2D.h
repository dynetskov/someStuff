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

 private:
  float x;
  float y;

};

#endif
