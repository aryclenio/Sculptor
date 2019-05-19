///A class derivated of FiguraGeometrica that draws a Sphere under the coordinates and the collor properties. This is made using the Draw function that uses a Sculptor as a parameter.

#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,radius,r,g,b,a;

public:
    PutSphere(int xc, int yc, int zc, int ra, int rb,int gb,int bb,int ab); ///Constructor of the class
    void draw(Sculptor &t); ///Draw function that receives the Sculptor.
    ~PutSphere(); ///Destructor of the class
};

#endif // PUTSPHERE_H
