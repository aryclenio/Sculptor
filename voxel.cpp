#include "voxel.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

Sculptor::Sculptor(int xx, int yy, int zz){
    nx = xx; ny = yy; nz = zz;
    if(nx <= 0 || ny <= 0 || nz <= 0){
        nx = ny = nz = 0;
    }
    c = new Voxel**[nx];
    if(c == nullptr){
        exit(0);
    }
    c[0] = new Voxel*[nx*ny];
    if(c[0] == nullptr){
        exit(0);
    }
    c[0][0] = new Voxel[nx*ny*nz];
    if(c[0][0] == nullptr){
        exit(0);
    }

    for(int i=0; i< nx; i++)
    {
        if (i<(nx-1))
        {
            c[i+1] = c[i]+ny;
        }
        for(int j=1; j< ny; j++)
        {
            c[i][j] = c[i][j-1]+nz;
            if(j==ny-1 && i!=(nx-1))
            {
                c[i+1][0] = c[i][j]+nz;
            }
        }
    }

}

Sculptor::~Sculptor(){
    if(nx == 0 || ny == 0 || nz == 0){
        return;
    }
    delete [] c[0][0];
    delete [] c[0];
    delete [] c;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    if(r >1){rp = 1;}else if(r <0){rp = 0;}else{rp = r;}
    if(g >1){gp = 1;}else if(g <0){gp = 0;}else{gp = r;}
    if(b >1){bp = 1;}else if(b <0){bp = 0;}else{bp = r;}
    if(alpha >1){ap = 1;}else if(alpha <0){ap = 0;}else{ap = alpha;}
}

void Sculptor::putVoxel(int x, int y, int z){
    c[x][y][z].isOn = true;
}
void Sculptor::cutVoxel(int x, int y, int z){
    c[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i<x1+1; i++){
        for (int j = y0; j<y1+1; j++){
            for (int k = z0; i<z1+1; k++){
                c[i][j][k].isOn = true;
                c[i][j][k].r = rp;
                c[i][j][k].g = gp;
                c[i][j][k].b = bp;
                c[i][j][k].a = ap;
            }
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i<x1+1; i++){
        for (int j = y0; j<y1+1; j++){
            for (int k = z0; i<z1+1; k++){
                c[i][j][k].isOn = false;
                c[i][j][k].r = rp;
                c[i][j][k].g = gp;
                c[i][j][k].b = bp;
                c[i][j][k].a = ap;
            }
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=0; i< xcenter; i++)
       {
           for(int j=0; j< ycenter; j++)
           {
               for(int k=0; k< zcenter; k++)
               {
                   if ((pow((i-xcenter),2)) + (pow((j-ycenter),2)) + (pow((k-zcenter),2)) <=radius)
                   {
                       c[i][j][k].isOn = true;
                       c[i][j][k].r = rp;
                       c[i][j][k].g = gp;
                       c[i][j][k].b = bp;
                       c[i][j][k].a = ap;
                   }
               }
           }
       }
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=0; i< xcenter; i++)
       {
           for(int j=0; j< ycenter; j++)
           {
               for(int k=0; k< zcenter; k++)
               {
                   if ((pow((i-xcenter),2)) + (pow((j-ycenter),2)) + (pow((k-zcenter),2)) <=radius)
                   {
                       c[i][j][k].isOn = false;
                       c[i][j][k].r = rp;
                       c[i][j][k].g = gp;
                       c[i][j][k].b = bp;
                       c[i][j][k].a = ap;
                   }
               }
           }
       }
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=0; i< rx; i++)
       {
           for(int j=0; j< ry; j++)
           {
               for(int k=0; k< rz; k++)
               {
                   if ((pow((i-xcenter),2)/(float)(pow(xcenter,2))) + ((pow((j-ycenter),2))/(float)(pow(ycenter,2))) + ((pow((k-zcenter),2))/(float)(pow(zcenter,2))) <=1.0)
                   {
                       c[i][j][k].isOn = true;
                       c[i][j][k].r = rp;
                       c[i][j][k].g = gp;
                       c[i][j][k].b = bp;
                       c[i][j][k].a = ap;
                   }
               }
           }
       }
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=0; i< rx; i++)
       {
           for(int j=0; j< ry; j++)
           {
               for(int k=0; k< rz; k++)
               {
                   if ((pow((i-xcenter),2)/(float)(pow(xcenter,2))) + ((pow((j-ycenter),2))/(float)(pow(ycenter,2))) + ((pow((k-zcenter),2))/(float)(pow(zcenter,2))) <=1.0)
                   {
                       c[i][j][k].isOn = false;
                       c[i][j][k].r = rp;
                       c[i][j][k].g = gp;
                       c[i][j][k].b = bp;
                       c[i][j][k].a = ap;
                   }
               }
           }
       }
}





