#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,radius;

public:
    PutSphere(int xc, int yc, int zc, int r);
    void draw(Sculptor &t);
    ~PutSphere();
};

#endif // PUTSPHERE_H
