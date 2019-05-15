#include "cutbox.h"

CutBox::CutBox(int xi, int xii, int yi, int yii, int zi, int zii)
{
    x0=xi; y0=yi; z0=zi;
    x1=xii; y1=yii; z1=zii;
}

CutBox::~CutBox()
{

}

void CutBox::draw(Sculptor &t){
    for (int i = x0; i<x1; i++){
        for (int j = y0; j<y1; j++){
            for (int k = z0; k<z1; k++){
                t.cutVoxel(i,j,k);
            }
        }
    }
}
