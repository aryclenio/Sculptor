///A class derivated of FiguraGeometrica that draws a Box under the coordinates and the collor properties. This is made using the Draw function that uses a Sculptor as a parameter.
#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class PutBox : public FiguraGeometrica{
    int x0,y0,z0,x1,y1,z1,r,g,b,a;

public:
    PutBox(int xi, int xii, int yi, int yii, int zi, int zii, int rb,int gb,int bb,int ab); ///Constructor of the class
    void draw(Sculptor &t); ///Draw function that receives the Sculptor.
    ~PutBox(); ///Destructor of the class
};
#endif // PUTBOX_H
