#include "cutsphere.h"
#include <math.h>
CutSphere::CutSphere(int xc, int yc, int zc, int r)
{
    xcenter = xc;
    ycenter = yc;
    zcenter = zc;
    radius  = r;
}

CutSphere::~CutSphere()
{

}

void CutSphere::draw(Sculptor &t){
    for(int i=xcenter-radius; i< xcenter+radius; i++)
    {
        for(int j=ycenter-radius; j< ycenter+radius; j++)
        {
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <=1.0)
                {
                    t.cutVoxel(i,j,k);
                }
            }
        }
    }
}
