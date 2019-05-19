#include "putbox.h"

PutBox::PutBox(int xi, int xii, int yi, int yii, int zi, int zii, int rb, int gb, int bb, int ab)
{
    x0=xi; y0=yi; z0=zi;
    x1=xii; y1=yii; z1=zii;
    r=rb; g=gb; b=bb; a=ab;
}

PutBox::~PutBox()
{

}

void PutBox::draw(Sculptor &t){
    for (int i = x0; i<x1; i++){
        for (int j = y0; j<y1; j++){
            for (int k = z0; k<z1; k++){
                t.setColor(r,g,b,a);
                t.putVoxel(i,j,k);
            }
        }
    }
}
