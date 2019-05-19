///A class derivated of FiguraGeometrica that erases an ellipsoid under the coordinates. This is made using the Draw function that uses a Sculptor as a parameter.
#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,rx, ry, rz;

public:
   CutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz); ///Constructor of the class
    void draw(Sculptor &t);///Draw function that receives the Sculptor.
    ~CutEllipsoid();///Destructor of the class
};

#endif // CUTELLIPSOID_H
