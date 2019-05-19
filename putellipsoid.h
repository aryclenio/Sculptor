///A class derivated of FiguraGeometrica that draws a Ellipsoid under the coordinates and the collor properties. This is made using the Draw function that uses a Sculptor as a parameter.

#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,rx, ry, rz, r,g,b,a;

public:
   PutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz, int rb,int gb,int bb,int ab); ///Constructor of the class
    void draw(Sculptor &t); ///Draw function that receives the Sculptor.
    ~PutEllipsoid(); ///Destructor of the class
};

#endif // PUTELLIPSOID_H
