///A class derivated of FiguraGeometrica that erases an sphere under the coordinates. This is made using the Draw function that uses a Sculptor as a parameter.
#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica{
    int xcenter,ycenter,zcenter,radius;

public:
    CutSphere(int xc, int yc, int zc, int r); ///Constructor of the class
    void draw(Sculptor &t);///Draw function that receives the Sculptor.
    ~CutSphere();///Destructor of the class
};



#endif // CUTSPHERE_H
