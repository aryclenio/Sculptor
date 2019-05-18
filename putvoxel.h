#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
class PutVoxel : public FiguraGeometrica{
    int x,y,z,r,g,b,a;

public:
    PutVoxel(int xi, int yi, int zi, int rb, int gb, int bb, int ab);
    void draw(Sculptor &t);
    ~PutVoxel();
};
#endif // PUTVOXEL_H
