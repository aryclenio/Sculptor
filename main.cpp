#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "sculptor.h"
#include "figurageometrica.h"
#include "voxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main(){

    ifstream figuresFile; //input text file
    figuresFile.open("/home/iago/Documents/MyTextFile.txt");

    vector<string> allLines; //array that get all lines from the input file
    string currentLine; //

    //File Reading

    if(figuresFile.is_open()){
        while(getline(figuresFile,currentLine)){
            allLines.push_back(currentLine);
        }
    }
    else{
        cout<<"Error opening the file";
    }

    //Sculptor Functions Calls

    float red, green, blue, transparency;
    string sculptorFunc; //string that gets the function at current line

    for(int i=0; i<allLines.size(); i++){

        stringstream lineParts(allLines[i]);
        lineParts >> sculptorFunc;

        if(i==0){
            if(sculptorFunc=="dim"){
                int width, height, depth;
                lineParts >> width >> height >> depth;
            }else{
                cout << "dim function needed at the first line" << endl;
                i=allLines.size();
            }
        }
        else if(sculptorFunc == "putvoxel"){
            int posX, posY, posZ;
            lineParts >> posX >> posY >> posZ >> red >> green >> blue >> transparency;
        }
        else if(sculptorFunc == "cutvoxel"){
            int posX, posY, posZ;
            lineParts >> posX >> posY >> posZ;
        }
        else if(sculptorFunc == "putbox"){
            int posX0, posX1, posY0, posY1, posZ0, posZ1;
            lineParts >> posX0 >> posX1 >> posY0 >> posY1 >> posZ0 >> posZ1 >> red >> green >> blue >> transparency;
        }
        else if(sculptorFunc == "cutbox"){
            int posX0, posX1, posY0, posY1, posZ0, posZ1;
            lineParts >> posX0 >> posX1 >> posY0 >> posY1 >> posZ0 >> posZ1;
        }
        else if(sculptorFunc == "putsphere"){
            int posX, posY, posZ, radius;
            lineParts >> posX >> posY >> posZ >> radius >> red >> green >> blue >> transparency;
        }
        else if(sculptorFunc == "cutsphere"){
            int posX, posY, posZ, radius;
            lineParts >> posX >> posY >> posZ >> radius;
        }
        else if(sculptorFunc == "putellipsoid"){
            int posX, posY, posZ, radiusX, radiusY, radiusZ;
            lineParts >> posX >> posY >> posZ >> radiusX >> radiusY >> radiusZ >> red >> green >> blue >> transparency;
        }
        else if(sculptorFunc == "cutellipsoid"){
            int posX, posY, posZ, radiusX, radiusY, radiusZ;
            lineParts >> posX >> posY >> posZ >> radiusX >> radiusY >> radiusZ;
        }
    }

}
