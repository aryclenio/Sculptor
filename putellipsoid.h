#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,rx, ry, rz;

public:
   PutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz);
    void draw(Sculptor &t);
    ~PutEllipsoid();
};

#endif // PUTELLIPSOID_H
