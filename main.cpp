#include <iostream>
#include <vector>
#include "sculptor.h"

using namespace std;

int main(){
    
    ifstream figuresFile; //input text file
    figuresFile.open("");
    
    vector<string> allLines; //array that get all lines from the input file
    string currentLine; //
    string sculptorFunc; //string that gets the function at current line
    
    if(sculptorFunc = "putvoxel"){
        int posX, posY, posZ;
        float red, green, blue, transparency;
    }
    else if(sculptorFunc = "cutvoxel"){
        int posX, posY, posZ;
    }
    else if(sculptorFunc = "putbox"){
        int posX0, posX1, posY0, posY1, posZ0, posZ1;
        float red, green, blue, transparency;
    }
    else if(sculptorFunc = "cutbox"){
        int posX0, posX1, posY0, posY1, posZ0, posZ1;
    }
    else if(sculptorFunc = "putsphere"){
        int posX, posY, posZ, radius;
        float red, green, blue, transparency;
    }
    else if(sculptorFunc = "cutsphere"){
        int posX, posY, posZ, radius;
    }
    else if(sculptorFunc = "putellipsoid"){
        int posX, posY, posZ, radiusX, radiusY, radiusZ;
        float red, green, blue, transparency;
    }
    else if(sculptorFunc = "cutellipsoid"){
        int posX, posY, posZ, radiusX, radiusY, radiusZ;
    }
}
