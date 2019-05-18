#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "sculptor.h"
#include "figurageometrica.h"
#include "voxel.h"
#include "putbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main(){

    ifstream figuresFile; //input text file
    figuresFile.open("/home/iago/Downloads/backupfinal/Sculptor/teste.txt");

    vector<string> allLines; //array that get all lines from the input file
    string currentLine; //

    //File Reading

    if(figuresFile.is_open()){
        while(getline(figuresFile,currentLine)){
            allLines.push_back(currentLine);
        }
    }
    else{
        cout << "Error opening the file" << endl;
        exit(0);
    }

    //Sculptor Functions Calls

    int red, green, blue, transparency;
    string sculptorFunc; //string that gets the function at current line
    vector<FiguraGeometrica*> figure;
    Sculptor *s;
    for(int i=0; i<allLines.size(); i++){

        stringstream lineParts(allLines[i]);
        lineParts >> sculptorFunc;

        if(i==0){
            if(sculptorFunc=="dim"){
                int width, height, depth;
                lineParts >> width >> height >> depth;
                s = new Sculptor(width, height, depth);
            }else{
                cout << "dim function needed at the first line" << endl;
                exit(0);
            }
        }
        else if(sculptorFunc == "putvoxel"){
            int posX, posY, posZ;
            lineParts >> posX >> posY >> posZ >> red >> green >> blue >> transparency;
            figure.push_back(new PutVoxel(posX, posY, posZ, red, green, blue, transparency));
            figure[i-1]->draw(*s);
        }
        else if(sculptorFunc == "cutvoxel"){
            int posX, posY, posZ;
            lineParts >> posX >> posY >> posZ;
            figure.push_back(new CutVoxel(posX, posY, posZ));
            figure[i-1]->draw(*s);
        }
        else if(sculptorFunc == "putbox"){
            int posX0, posX1, posY0, posY1, posZ0, posZ1;
            lineParts >> posX0 >> posX1 >> posY0 >> posY1 >> posZ0 >> posZ1 >> red >> green >> blue >> transparency;
            figure.push_back(new PutBox(posX0, posX1, posY0, posY1, posZ0, posZ1 ,red, green, blue, transparency));
            figure[i-1]->draw(*s);
        }
        else if(sculptorFunc == "cutbox"){
            int posX0, posX1, posY0, posY1, posZ0, posZ1;
            lineParts >> posX0 >> posX1 >> posY0 >> posY1 >> posZ0 >> posZ1;
            figure.push_back(new CutBox(posX0, posX1, posY0, posY1, posZ0, posZ1));
            figure[i-1]->draw(*s);
        }
        else if(sculptorFunc == "putsphere"){
            int posX, posY, posZ, radius;
            lineParts >> posX >> posY >> posZ >> radius >> red >> green >> blue >> transparency;
            figure.push_back(new PutSphere(posX, posY, posZ, radius, red, green, blue, transparency));
            figure[i-1]->draw(*s);
        }
        else if(sculptorFunc == "cutsphere"){
            int posX, posY, posZ, radius;
            lineParts >> posX >> posY >> posZ >> radius;
            figure.push_back(new CutSphere(posX, posY, posZ, radius));
            figure[i-1]->draw(*s);
        }
        else if(sculptorFunc == "putellipsoid"){
            int posX, posY, posZ, radiusX, radiusY, radiusZ;
            lineParts >> posX >> posY >> posZ >> radiusX >> radiusY >> radiusZ >> red >> green >> blue >> transparency;
            figure.push_back(new PutEllipsoid(posX, posY, posZ, radiusX, radiusY, radiusZ, red, green, blue, transparency));
            figure[i-1]->draw(*s);
        }
        else if(sculptorFunc == "cutellipsoid"){
            int posX, posY, posZ, radiusX, radiusY, radiusZ;
            lineParts >> posX >> posY >> posZ >> radiusX >> radiusY >> radiusZ;
            figure.push_back(new CutEllipsoid(posX, posY, posZ, radiusX, radiusY, radiusZ));
            figure[i-1]->draw(*s);
        }
    }
    s->writeOFF("/home/iago/Downloads/backupfinal/Sculptor/t.off");
    return 0;
}
