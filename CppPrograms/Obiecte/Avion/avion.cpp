//Nume fila: avion.cpp
#include "avion.h"
Avion::Avion(string prod, string model, int viteza, int locuri){
    _producator = prod;
    _model = model;
    _vitezaMaxima = viteza;
    _nrLocuri = locuri;
}
Avion::Avion(const Avion& av){
    _producator=av._producator;
    _model=av._model;
    _vitezaMaxima = av._vitezaMaxima;
    _nrLocuri = av._nrLocuri;
}
void Avion::creazaAvion(){
    cout<<"Introduceti un model de avion."<<endl;
    cout<<"Introduceti producatorul avionului: ";
    getline(cin, _producator);
    cout<<"Introduceti modelul avionului: ";
    getline(cin, _model);
    cout<<"Introduceti viteza maxima de deplasare: ";
    cin>>_vitezaMaxima;
    cout<<"Introduceti numarul de locuri: ";
    cin>>_nrLocuri;
}
void Avion::afiseaza(){
    cout<<"PRODUCATOR:         "<<_producator<<endl;
    cout<<"MODEL:              "<<_model<<endl;
    cout<<"VITEZA MAXIMA:      "<<_vitezaMaxima<<endl;
    cout<<"NUMAR LOCURI:       "<<_nrLocuri<<endl;
    cout<<endl;
}
ostream& operator<<(ostream& os, const Avion& av){
    os<<"Producator: "<<av._producator<<" MODEL: "<<av._model<<'\n';
    os<<"Viteza maxima: "<<av._vitezaMaxima<<" Numar locuri: "<<av._nrLocuri<<'\n';
    return os;
}
