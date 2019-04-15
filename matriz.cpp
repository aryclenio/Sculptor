#include "matriz.h"
#include <iostream>
using namespace std;
//Construtor
Matriz::Matriz(int _nl, int _nc){
    nl = _nl; nc = _nc;
    x = new int*[nl];
    if (x == nullptr){
        exit(0);
    }
    x[0] = new int [nl*nc];
    if (x[0] == nullptr){
        exit(0);
    }
    for(int i = 0; i<nl; i++){
        x[i] = x[i-1] + nc;
    }
}

Matriz::~Matriz(){
    delete [] x;
    delete [] x[0];
}

void Matriz::print(){
    for(int i = 0; i<nl; i++){
        for(int j = 0; j<nc; j++){
            cout<< x[i][j] << " ";
        }
    cout<<endl;
    }
}
