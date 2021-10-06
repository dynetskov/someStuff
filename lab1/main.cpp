#include "Vector2D.h"

int main()
{
  Vector2D vecA;
  Vector2D vecB(6, 8);
  Vector2D vecC = vecB.normalize();

  vecA.view();
  vecB.view();
  vecC.view();

  float x = vecA.normal();
  float y = vecC.normal();
  cout << x << endl << y << endl;

  /*
  Vector2D vecC = vecA.normalize();
  vecA = vecA.normalize();*/

  //strange scaling(look for it later)
  /*vecA = vecA * 2;
  vecA.view();*/

  //vecC /= 2
  //vecC *= 2
  //int a = vecA * vecB
  //vecC = 8*vecA ????

  return 0;
}
