///Abstract class made to represent primitive objects that have a virtual draw function.
///This makes any object to draw itself into a Sculptor type.
#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"
class FiguraGeometrica{

public:
    //FiguraGeometrica();
    virtual void draw(Sculptor &t)=0; ///Draw function that receives the Sculptor.
    virtual  ~FiguraGeometrica(){}; ///Destructor of the class
};
#endif // FIGURAGEOMETRICA_H
