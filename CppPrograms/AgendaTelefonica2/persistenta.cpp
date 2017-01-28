/**
    @file: persistenta.cpp
*/
#include "persistenta.h"

void Persistenta::salveazaInFila( char const* fila, Contact con){
    ofstream myFile;
    myFile.open(fila);
    if(myFile.is_open()){
        myFile<<con;
        myFile.close();
    } else {
        cout<<"Fila "<<fila<<" nu a fost deschisa!"<<endl;
    }
}
void Persistenta::citesteDinFila(char const* fila){
    string line;
    ifstream myFile;
    myFile.open(fila);
    if(myFile.is_open()){
        while(getline(myFile, line)){
            cout<<line<<'\n';
        }
        myFile.close();
    } else {
        cout<<"Fila "<<fila<<" nu a fost deschisa!"<<endl;
    }
}
