#include <iostream>
#include "voxel.h"

using namespace std;

int main()
{
  Sculptor s(5,5,5);
  s.setColor(1, 0, 0, 1);
  s.putVoxel(0,0,0);
  s.putVoxel(1,0,0);
  s.putVoxel(0,1,0);
  s.putVoxel(1,1,0);
  s.putVoxel(0,0,1);
  s.putVoxel(1,0,1);
  s.putVoxel(0,1,1);
  s.putVoxel(1,1,1);
  s.writeOFF("C:/Users/MatrizD42018/Downloads/Sculptor-master/Sculptor-master/test.off");
  s.writeVECT("C:/Users/MatrizD42018/Downloads/Sculptor-master/Sculptor-master/test.vect");
}
