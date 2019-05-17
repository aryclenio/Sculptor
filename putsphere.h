#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,radius,r,g,b,a;

public:
    PutSphere(int xc, int yc, int zc, int ra, int rb,int gb,int bb,int ab);
    void draw(Sculptor &t);
    ~PutSphere();
};

#endif // PUTSPHERE_H
