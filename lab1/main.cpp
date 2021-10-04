#include "Vector2D.h"

int main()
{
  Vector2D vecA;
  Vector2D vecB(6, 8);
  Vector2D vecC = vecB + vecA;

  vecA.view();
  vecB.view();
  vecC.view();

  //strange scaling(look for it later)
  /*vecA = vecA * 2;
  vecA.view();*/

  /*float a = vecA * vecB;
  cout << a << endl;*/

  //vecC /= 2
  //vecC *= 2
  //int a = vecA * vecB
  //vecC = 8*vecA ????

  return 0;
}
