#include "putellipsoid.h"
#include <math.h>
PutEllipsoid::PutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz)
{
    xcenter = xc;
    ycenter = yc;
    zcenter = zc;
    rx = radx;
    ry = rady;
    rz = radz;
}

PutEllipsoid::~PutEllipsoid()
{

}

void PutEllipsoid::draw(Sculptor &t){
    for(int i=xcenter-rx; i< xcenter+rx; i++)
    {
        for(int j=ycenter-ry; j< ycenter+ry; j++)
        {
            for(int k=zcenter - rz; k< zcenter + rz; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <=1.0)
                {
                   t.putVoxel(i,j,k);
                }
            }
        }
    }
}
