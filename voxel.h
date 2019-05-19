///
#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using namespace std;

struct Voxel {
  float r,g,b; ///Properties of the collor mix, using values between 0 and 1.
  float a; ///Value over 0 to 1 that indicates the transparency of the voxel. 0 indicates full transparency and 1 indicates full opacity.
  bool isOn; ///A true or false variable that that validates if the voxel will be shown in the sculpture.
};

#endif
