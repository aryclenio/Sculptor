#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,radius;

public:
    CutSphere(int xc, int yc, int zc, int r);
    void draw(Sculptor &t);
    ~CutSphere();
};



#endif // CUTSPHERE_H
