///A class Sculptor is declarated here to call all the base functions.
#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
class Sculptor{
private:
  int nx, ny, nz;
  float rp,gp,bp,ap;
  Voxel ***c;
public:
  Sculptor(int xx=0, int yy=0, int zz=0); ///Class Constructor that sequentially allocates the memory of the sculpture's space.
  ~Sculptor(); ///Class Destructor that frees the memory of the sculpture's space.
  void setColor(float r, float g, float b, float alpha); ///Sets the colors' components and transparency.
  void putVoxel(int x, int y, int z); ///Activates a Voxel in the (x,y,z) position of the sculpture's space.
  void cutVoxel(int x, int y, int z); ///Deactivates the Voxel in the (x,y,z) position of the sculpture's space.
  void writeOFF(string filename); ///Saves the Voxel sculpture on a OFF format file filename.
  void writeVECT(string filename); ///Saves the Voxel sculpture on a VECT format file filename.
};

#endif // SCULPTOR_H
