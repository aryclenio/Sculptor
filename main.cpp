#include <iostream>
#include "voxel.h"

using namespace std;

int main()
{
  Sculptor s(100,100,100);
  s.setColor(1, 1, 1, 1);
  s.putBox(50,95,50,95,50,95);
  s.cutBox(90,95,90,95,90,95);
  s.setColor(1, 0, 0, 0.5);
  s.putSphere(10,10,10,9);
  s.putEllipsoid(50,50,50,49,49,49);
  s.cutSphere(25,25,25,24);
  s.cutEllipsoid(40,40,40,39,39,39);
  s.writeOFF("C:/Users/axbli/Downloads/Sculptor-master (2)/Sculptor-master/test.off");
  s.writeVECT("C:/Users/axbli/Downloads/Sculptor-master (2)/Sculptor-master/test.vect");
}
