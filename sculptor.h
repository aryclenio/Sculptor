#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "voxel.h"
class Sculptor{
private:
  // no. linhas e colunas
  int nx, ny, nz;
  float rp,gp,bp,ap;
  Voxel ***c;
public:
  Sculptor(int xx=0, int yy=0, int zz=0);
  ~Sculptor();
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void writeOFF(string filename);
  void writeVECT(string filename);
};

#endif // SCULPTOR_H
