#include "cutvoxel.h"

CutVoxel::CutVoxel(int xi, int yi, int zi)
{
    x=xi; y=yi; z=zi;

}

CutVoxel::~CutVoxel()
{

}

void CutVoxel::draw(Sculptor &t){
    t.cutVoxel(x,y,z);
}
