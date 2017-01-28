/**
    @file: persistenta.cpp
*/
#include "persistenta.h"

void Persistenta::salveazaInFila( char const* fila, Contact con){
    ofstream myFile;
    myFile.open(fila, ios::app);
    if(myFile.is_open()){
        myFile<<con<<'\n';
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
void Persistenta::salveazaInFila(string file, Contact con){
    ofstream scrie(file.c_str(), ios::app);
    if(scrie.is_open()){
        scrie<<con<<'\n';
        scrie.close();
    } else {
        cout<<"Fila "<<file<<" nu a fost deschisa!"<<endl;
    }
}
void Persistenta::citesteDinFila(string fila){
    string linie;
    ifstream citeste(fila.c_str());
    if(citeste.is_open()){
        while(getline(citeste, linie)){
            cout<<linie<<'\n';
        }
        citeste.close();
    } else {
        cout<<"Fila "<<fila<<" nu a fost deschisa!"<<endl;
    }
}
