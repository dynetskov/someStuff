#include "Vector2D.h"

int main()
{

  Vector2D vecA;//default(3,4)
  Vector2D vecB(6, 8);//by value
  Vector2D vecC = vecB;//copy

  cout << endl << "Default constructor of vector A:" << endl;
  vecA.view();

  cout << endl << "Value constructor of vector B:" << endl;
  vecB.view();

  cout << endl << "Copy constructor of vector C = vector B:" << endl;
  vecC.view();

  cout << endl << "C = A+B:" << endl;
  vecC = vecA+vecB;
  vecC.view();

  cout << endl << "C = A-B:" << endl;
  vecC = vecA - vecB;
  vecC.view();

  cout << endl << "A*B(scalar):" << vecA*vecB << endl;

  cout << endl << "3*A:" << endl;
  vecA *= 3;
  vecA.view();

  cout << endl << "A/0.5:" << endl;
  vecA /= 0.5;
  vecA.view();

  cout << endl << "A = -A:" << endl;
  vecA.reverse();
  vecA.view();

  cout << endl << "A = B:" << endl;
  vecA = vecB;
  vecA.view();

  cout << endl << "A = normalize B" << endl;
  vecA = vecB.normalize();
  vecA.view();

  cout << endl << "normal of vector B:" << vecB.normal() << endl;

  cout << endl << "get of vector C: x = " << vecC.getX() << " y = " << vecC.getY() << endl;

  cout << endl << "set of vector C(1,2):" << endl;
  vecC.setX(1);
  vecC.setY(2);
  vecC.view();

  cout << endl << "indexation of vector C" << endl;
  float valueX = vecC[0];
  cout << "x = " << valueX << endl;

  vecC[1] = valueX+5;
  cout << "y = x+5 =  " << vecC.getY() << endl;

  cout << endl << "rotation of vector C at angle = pi/2:" << endl;
  vecC.rotate(M_PI_2);
  vecC.view();

  return 0;
}
