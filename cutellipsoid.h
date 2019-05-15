#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,rx, ry, rz;

public:
   CutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz);
    void draw(Sculptor &t);
    ~CutEllipsoid();
};

#endif // CUTELLIPSOID_H
