///A class derivated of FiguraGeometrica that draws a Voxel under the coordinates and the collor properties. This is made using the Draw function that uses a Sculptor as a parameter.

#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
class PutVoxel : public FiguraGeometrica{
    int x,y,z,r,g,b,a;

public:
    PutVoxel(int xi, int yi, int zi, int rb, int gb, int bb, int ab); ///Constructor of the class
    void draw(Sculptor &t); ///Draw function that receives the Sculptor.
    ~PutVoxel(); ///Destructor of the class
};
#endif // PUTVOXEL_H
