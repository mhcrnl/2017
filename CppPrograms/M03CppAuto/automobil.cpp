/**
    @Author: Mihai Cornel
    @file: automobil.cpp
    @date: Martie 2017
*/

#include "automobil.h"

Automobil::Automobil(string model, string nrInmatriculare, unsigned int nrKm, double consum){
    _model = model;
    _nrInmatriculare = nrInmatriculare;
    _nrKm = nrKm;
    _consum = consum;
}
ostream& operator<<(ostream& os, Automobil const& aut){
    os<<aut._model<<" "<<aut._nrInmatriculare<<" "<<aut._nrKm<<" "<<aut._consum<<endl;
    return os;
}
double Automobil::consumCarburant() const{
    double carburant;
    carburant = (_nrKm/100)*_consum;
    return carburant;
}
double Automobil::costTotalCarburant(double pretLitru) const{
    return (consumCarburant()*pretLitru);
}
void Automobil::setModel(string const& model){
    _model = model;
}
string Automobil::getModel() const{
    return _model;
}
