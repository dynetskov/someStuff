#include "Vector2D.h"

int main()
{
  Vector2D vecA;
  Vector2D vecB(6, 8);
  Vector2D vecC = vecB;

  vecA.view();
  vecB.view();
  vecC.view();

  return 0;
}
