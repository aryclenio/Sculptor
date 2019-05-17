#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,rx, ry, rz, r,g,b,a;

public:
   PutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz, int rb,int gb,int bb,int ab);
    void draw(Sculptor &t);
    ~PutEllipsoid();
};

#endif // PUTELLIPSOID_H
