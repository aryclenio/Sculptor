#include "putvoxel.h"

PutVoxel::PutVoxel(int xi, int yi, int zi, int rb, int gb, int bb, int ab)
{
    x=xi; y=yi; z=zi;
    r=rb; g=gb; b=bb; a=ab;
}

PutVoxel::~PutVoxel()
{

}

void PutVoxel::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    t.putVoxel(x,y,z);
}
