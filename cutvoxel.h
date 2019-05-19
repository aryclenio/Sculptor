///A class derivated of FiguraGeometrica that erases an specific voxel under the coordinates. This is made using the Draw function that uses a Sculptor as a parameter.
#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
class CutVoxel : public FiguraGeometrica{
    int x,y,z;

public:
    CutVoxel(int xi, int yi, int zi); ///Constructor of the class
    void draw(Sculptor &t);///Draw function that receives the Sculptor.
    ~CutVoxel();///Destructor of the class
};
#endif // CUTVOXEL_H
