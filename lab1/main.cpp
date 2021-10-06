#include "Vector2D.h"

int main()
{
  Vector2D vecA;
  Vector2D vecB(6, 8);
  Vector2D vecC = vecB;

  vecA.view();
  vecB.view();
  vecC.view();

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
