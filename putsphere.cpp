#include "putsphere.h"

#include <math.h>
PutSphere::PutSphere(int xc, int yc, int zc, int ra, int rb,int gb,int bb,int ab)
{
    xcenter = xc;
    ycenter = yc;
    zcenter = zc;
    radius  = ra;
    r = rb; g = gb; b = bb; a=ab;
}

PutSphere::~PutSphere()
{

}

void PutSphere::draw(Sculptor &t){
    for(int i=xcenter-radius; i< xcenter+radius; i++)
    {
        for(int j=ycenter-radius; j< ycenter+radius; j++)
        {
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <=1.0)
                {
                    t.setColor(r,g,b,a);
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
