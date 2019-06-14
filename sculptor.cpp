#include "sculptor.h"
#include "mainwindow.h"
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

vector<vector<Voxel>> Sculptor::readMx(int dim, int pl){
    vector<vector<Voxel>> m;
    vector<Voxel> l;

    //fazer ifs de cada plano
    if (pl == XY){
        l.resize(ny);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                l[j].isOn = c[i][j][dim].isOn;
                l[j].r = c[i][j][dim].r;
                l[j].g = c[i][j][dim].g;
                l[j].b = c[i][j][dim].b;
                l[j].a = c[i][j][dim].a;
            }
            m.push_back(l);
        }
    }
    if (pl == YZ){
        l.resize(nz);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                l[j].isOn = c[i][j][dim].isOn;
                l[j].r = c[i][j][dim].r;
                l[j].g = c[i][j][dim].g;
                l[j].b = c[i][j][dim].b;
                l[j].a = c[i][j][dim].a;
            }
            m.push_back(l);
        }
    }

    if (pl == ZX){
        l.resize(nx);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                l[j].isOn = c[i][j][dim].isOn;
                l[j].r = c[i][j][dim].r;
                l[j].g = c[i][j][dim].g;
                l[j].b = c[i][j][dim].b;
                l[j].a = c[i][j][dim].a;
            }
            m.push_back(l);
        }
    }
    l.clear();
    return m;
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
    for (int i = x0; i<x1; i++){
        for (int j = y0; j<y1; j++){
            for (int k = z0; k<z1; k++){
                putVoxel(i,j,k);
            }
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i<x1; i++){
        for (int j = y0; j<y1; j++){
            for (int k = z0; k<z1; k++){
                cutVoxel(i,j,k);
            }
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=xcenter-radius; i< xcenter+radius; i++)
    {
        for(int j=ycenter-radius; j< ycenter+radius; j++)
        {
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <=1.0)
                {
                    putVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i=xcenter-radius; i< xcenter+radius; i++)
    {
        for(int j=ycenter-radius; j< ycenter+radius; j++)
        {
            for(int k=zcenter-radius; k< zcenter+radius; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <=1.0)
                {
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=xcenter-rx; i< xcenter+rx; i++)
    {
        for(int j=ycenter-ry; j< ycenter+ry; j++)
        {
            for(int k=zcenter - rz; k< zcenter + rz; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <=1.0)
                {
                   putVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i=xcenter-rx; i< xcenter+rx; i++)
    {
        for(int j=ycenter-ry; j< ycenter+ry; j++)
        {
            for(int k=zcenter - rz; k< zcenter + rz; k++)
            {
                if (((float)pow((i-xcenter),2)/(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <=1.0)
                {
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(string filename){
    char s[nx][ny][nz];
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
    bool surx, sury, surz;
    ofstream outfile (filename);
    outfile<<"OFF"<<endl;
    for(int i = 1; i < nx-1; i++){
        for(int j = 1; j < ny-1; j++){
            for(int k = 1; k < nz-1; k++){
                surx = false; sury = false; surz=false;
                //if the point is valid, check if it is surrounded
                if(c[i-1][j][k].isOn && c[i+1][j][k].isOn){surx = true;}
                if(c[i][j-1][k].isOn && c[i][j+1][k].isOn){sury = true;}
                if(c[i][j][k-1].isOn && c[i][j][k+1].isOn){surz = true;}
                if(surx && sury && surz){
                    s[i][j][k] = 1;
                }

            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (c[i][j][k].isOn && s[i][j][k] == 0){
                    nvox++;
                }
            }
        }
    }
    cout<<(nvox);
    outfile << 8*nvox << " " << 6*nvox << " " << 0 << std::endl;


     for(int k=0;k<nz; k++){
         for(int j=0;j<ny;j++){
             for (int i=0;i<nx;i++) {
                 if(c[i][j][k].isOn && s[i][j][k] == 0){
                         outfile<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                         outfile<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                         outfile<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                         outfile<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                         outfile<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                 }
             }
         }

     }
     int nfc =0;
     for(int k=0;k<nz; k++){
          for(int j=0;j<ny;j++){
              for (int i=0;i<nx;i++) {
                  if(c[i][j][k].isOn && s[i][j][k] == 0){
                      outfile<<"4 "<<0+nfc*8<<" "<<3+nfc*8<<" "<<2+nfc*8<<" "<<1+nfc*8<<" "<<c[i][j][k].r<<" "<<c[i][j][k].g<<" "<<c[i][j][k].b<<" "<<c[i][j][k].a<<endl
                          <<"4 "<<4+nfc*8<<" "<<5+nfc*8<<" "<<6+nfc*8<<" "<<7+nfc*8<<" "<<c[i][j][k].r<<" "<<c[i][j][k].g<<" "<<c[i][j][k].b<<" "<<c[i][j][k].a<<endl
                          <<"4 "<<0+nfc*8<<" "<<1+nfc*8<<" "<<5+nfc*8<<" "<<4+nfc*8<<" "<<c[i][j][k].r<<" "<<c[i][j][k].g<<" "<<c[i][j][k].b<<" "<<c[i][j][k].a<<endl
                          <<"4 "<<0+nfc*8<<" "<<4+nfc*8<<" "<<7+nfc*8<<" "<<3+nfc*8<<" "<<c[i][j][k].r<<" "<<c[i][j][k].g<<" "<<c[i][j][k].b<<" "<<c[i][j][k].a<<endl
                          <<"4 "<<3+nfc*8<<" "<<7+nfc*8<<" "<<6+nfc*8<<" "<<2+nfc*8<<" "<<c[i][j][k].r<<" "<<c[i][j][k].g<<" "<<c[i][j][k].b<<" "<<c[i][j][k].a<<endl
                          <<"4 "<<1+nfc*8<<" "<<2+nfc*8<<" "<<6+nfc*8<<" "<<5+nfc*8<<" "<<c[i][j][k].r<<" "<<c[i][j][k].g<<" "<<c[i][j][k].b<<" "<<c[i][j][k].a<<endl;
                      nfc++;
                  }


              }
          }

      }
    outfile.close();
}
void Sculptor::writeVECT(string filename){
    char s[nx][ny][nz];
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                s[i][j][k] = 0;
            }
        }
    }
    int nvox = 0;
    bool surx = false, sury = false, surz=false;
    ofstream outfile (filename);
    outfile << "VECT" << endl;
    for(int i = 1; i < nx-1; i++){
        for(int j = 1; j < ny-1; j++){
            for(int k = 1; k < nz-1; k++){
                surx = false, sury = false, surz=false;
                //if the point is valid, check if it is surrounded
                if(c[i-1][j][k].isOn && c[i+1][j][k].isOn){surx = true;}
                if(c[i][j-1][k].isOn && c[i][j+1][k].isOn){sury = true;}
                if(c[i][j][k-1].isOn && c[i][j][k+1].isOn){surz = true;}
                if(surx && sury && surz){ s[i][j][k] = 1;}
            }
        }
    }
    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (c[i][j][k].isOn && s[i][j][k] == 0){
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




