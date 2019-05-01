#include <iostream>
#include "voxel.h"

using namespace std;

int main()
{
  Sculptor s(30,30,30);
  s.setColor(1, 0, 0, 1);
  s.putEllipsoid(10,10,10,20,20,20);
  s.writeOFF("C:/Users/ARY/Downloads/Sculptor-master/Sculptor-master/test.off");
  s.writeVECT("C:/Users/ARY/Downloads/Sculptor-master/Sculptor-master/test.vect");
}
