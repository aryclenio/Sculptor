#ifndef MATRIZ_H
#define MATRIZ_H

struct Voxel {
  float r,g,b; // Colors
  float a;
  bool isOn; // Included or not
};

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
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

};

#endif // MATRIZ_H
