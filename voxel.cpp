#include "voxel.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
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
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                c[i][j][k].isOn = false;
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
    if(g >1){gp = 1;}else if(g <0){gp = 0;}else{gp = g;}
    if(b >1){bp = 1;}else if(b <0){bp = 0;}else{bp = b;}
    if(alpha >1){ap = 1;}else if(alpha <0){ap = 0;}else{ap = alpha;}
}

void Sculptor::putVoxel(int x, int y, int z){
    c[x][y][z].isOn = true;
    c[x][y][z].r = rp;
    c[x][y][z].g = gp;
    c[x][y][z].b = bp;
    c[x][y][z].a = ap;
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

void Sculptor::writeOFF(string filename){
    int s[nx][ny][nz];
    //writing zeroes on the array to verify
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                s[i][j][k] = 0;
            }
        }
    }
    int nvox = 0;
    //variables to check the valid position
    bool ti = true, tj = true, tk = true, surx = false, sury = false, surz=false;
    ofstream outfile (filename);
    outfile<<"OFF"<<endl;
    for(int i = 1; i < nx-1; i++){
        for(int j = 1; j < ny-1; j++){
            for(int k = 1; k < nz-1; k++){
                //if the point is valid, check if it is surrounded
                if(c[i-1][j][k].isOn && c[i+1][j][k].isOn){surx = true;}
                if(c[i][j-1][k].isOn && c[i][j+1][k].isOn){sury = true;}
                if(c[i][j][k-1].isOn && c[i][j][k+1].isOn){surz = true;}
                if(surx || sury || surz){
                    s[i][j][k] = 1;
                }

            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (c[i][j][k].isOn){
                    nvox++;
                }
            }
        }
    }
    cout<<(nvox);
    outfile << 8*nvox << " " << 6*nvox << " " << 0 << std::endl;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (c[i][j][k].isOn && s[i][j][k] == 0){
                    outfile << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    outfile << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    outfile << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    outfile << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    outfile << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    outfile << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    outfile << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    outfile << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (c[i][j][k].isOn && s[i][j][k] ==0){
                    outfile << 4 << " " << 0 + 8*i << " " << 3 + 8*i << " " << 2 + 8*i << " " << 1 + 8*i << " " << c[i][j][k].r << " " << c[i][j][k].g << " " << c[i][j][k].b << " " << c[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 4 + 8*i << " " << 5 + 8*i << " " << 6 + 8*i << " " << 7 + 8*i << " " << c[i][j][k].r << " " << c[i][j][k].g << " " << c[i][j][k].b << " " << c[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 0 + 8*i << " " << 1 + 8*i << " " << 5 + 8*i << " " << 4 + 8*i << " " << c[i][j][k].r << " " << c[i][j][k].g << " " << c[i][j][k].b << " " << c[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 0 + 8*i << " " << 4 + 8*i << " " << 7 + 8*i << " " << 3 + 8*i << " " << c[i][j][k].r << " " << c[i][j][k].g << " " << c[i][j][k].b << " " << c[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 3 + 8*i << " " << 7 + 8*i << " " << 6 + 8*i << " " << 2 + 8*i << " " << c[i][j][k].r << " " << c[i][j][k].g << " " << c[i][j][k].b << " " << c[i][j][k].a << " " << endl;
                    outfile << 4 << " " << 1 + 8*i << " " << 2 + 8*i << " " << 6 + 8*i << " " << 5 + 8*i << " " << c[i][j][k].r << " " << c[i][j][k].g << " " << c[i][j][k].b << " " << c[i][j][k].a << " " << endl;
                }
            }
        }
    }
    outfile.close();
}
void Sculptor::writeVECT(string filename){
    int s[nx][ny][nz];
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                s[i][j][k] = 0;
            }
        }
    }
    int nvox = 0;
    bool ti = true, tj = true, tk = true, surx = false, sury = false, surz=false;
    ofstream outfile (filename);
    outfile << "VECT" << endl;
    for(int i = 1; i < nx-1; i++){
        for(int j = 1; j < ny-1; j++){
            for(int k = 1; k < nz-1; k++){
                //if the point is valid, check if it is surrounded
                if(c[i-1][j][k].isOn && c[i+1][j][k].isOn){surx = true;}
                if(c[i][j-1][k].isOn && c[i][j+1][k].isOn){sury = true;}
                if(c[i][j][k-1].isOn && c[i][j][k+1].isOn){surz = true;}
                if(surx || sury || surz){ s[i][j][k] = 1;}
            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (c[i][j][k].isOn){
                    nvox++;
                }
            }
        }
    }
        outfile << nvox << " " << nvox << " " << nvox << endl;
    for (int i =0;i<nvox; i++) {
        outfile << "1" <<" ";
    }
    outfile << endl;
    for (int i =0;i<nvox; i++) {
        outfile << "1" <<" ";
    }
    outfile << endl;
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){             
                if (c[i][j][k].isOn && s[i][j][k] == 0){
                    outfile << i <<" "<< j <<" "<< k << endl;
                }
            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(surx || sury || surz){ c[i][j][k].isOn = false;}
                if (c[i][j][k].isOn && s[i][j][k] == 0){
                    outfile << c[i][j][k].r <<" "<< c[i][j][k].g <<" "<< c[i][j][k].b <<" "<< c[i][j][k].a << endl;
                }
            }
        }
    }
    outfile.close();
}




