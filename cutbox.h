#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

class CutBox : public FiguraGeometrica{
    int x0,y0,z0,x1,y1,z1;

public:
    CutBox(int xi, int xii, int yi, int yii, int zi, int zii);
    void draw(Sculptor &t);
    ~CutBox();
};

#endif // CUTBOX_H
