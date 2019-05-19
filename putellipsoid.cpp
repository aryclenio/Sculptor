#include "putellipsoid.h"
#include <math.h>

PutEllipsoid::PutEllipsoid(int xc, int yc, int zc, int radx, int rady, int radz, int rb,int gb,int bb,int ab)
{
    xcenter = xc;
    ycenter = yc;
    zcenter = zc;
    rx = radx;
    ry = rady;
    rz = radz;
    r = rb; g = gb; b = bb; a = ab;
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
                   t.setColor(r,g,b,a);
                   t.putVoxel(i,j,k);
                }
            }
        }
    }
}
