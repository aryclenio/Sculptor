#include "cutvoxel.h"

PutVoxel::PutVoxel(int xi, int yi, int zi)
{
    x=xi; y=yi; z=zi;

}

PutVoxel::~PutVoxel()
{

}

void PutVoxel::draw(Sculptor &t){
    t.cutVoxel(x,y,z);
}
