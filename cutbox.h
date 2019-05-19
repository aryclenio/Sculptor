///A class derivated of FiguraGeometrica that draws a specific voxel under the coordinates. This is made using the Draw function that uses a Sculptor as a parameter.
#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class CutBox : public FiguraGeometrica{
    int x0,y0,z0,x1,y1,z1;

public:
    CutBox(int xi, int xii, int yi, int yii, int zi, int zii); ///Constructor of the class
    void draw(Sculptor &t); ///Draw function that receives the Sculptor.
    ~CutBox();///Destructor of the class
};

#endif // CUTBOX_H
