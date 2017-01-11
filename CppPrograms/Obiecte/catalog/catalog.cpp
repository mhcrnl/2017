//@file: catalog.cpp
#include "catalog.h"
#include "elev.h"
#include <iostream>
using namespace std;

void Catalog::VizualizareNota(const Elev &elev) const{
    cout<<"Catalog::VizualizareNota Elev:"<<elev.Nume()<<endl;
}

void Catalog::ModificareNota(const Elev &elev, int nota){
    cout<<"Catalog::ModificareNota Elev:"<<elev.Nume()<<"Nota: "<<nota<<endl;
}
