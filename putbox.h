#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

class PutBox : public FiguraGeometrica{
    int x0,y0,z0,x1,y1,z1;

public:
    PutBox(int xi, int xii, int yi, int yii, int zi, int zii);
    void draw(Sculptor &t);
    ~PutBox();
};
#endif // PUTBOX_H
