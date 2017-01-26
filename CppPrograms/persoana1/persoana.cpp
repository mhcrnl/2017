/**
    @file: persoana.cpp
*/
#include "persoana.h"
Persoana::Persoana(string nume){
    _nume=nume;
}
Persoana::~Persoana(){}
ostream& operator<<(ostream& os, const Persoana& pers){
    os<<pers._nume<<endl;
    return os;
}
void Persoana::setNume(const string& nume){
    _nume=nume;
}
string Persoana::getNume(void){
    return _nume;
}
