#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class PutBox : public FiguraGeometrica{
    int x0,y0,z0,x1,y1,z1,r,g,b,a;

public:
    PutBox(int xi, int xii, int yi, int yii, int zi, int zii, int rb,int gb,int bb,int ab);
    void draw(Sculptor &t);
    ~PutBox();
};
#endif // PUTBOX_H
