/**
    @Author: Mihai Cornel
    @File:   carte.cpp
    @Date:   Martie 2017
*/
#include "carte.h"

int Carte::_nrCrt(0); //initializarea variabilei statice

Carte::Carte(string titlu="", string autor="", string editura="", int an=0, int nrPagini=0){
    _titlu=titlu;
    _autor=autor;
    _editura=editura;
    _an=an;
    _nrPagini=nrPagini;
    ++_nrCrt;
}
int Carte::getNrCrt(){
    return _nrCrt;
}
ostream& Carte::operator<<(ostream& os, Carte const& carte){
    os<<carte._titlu<<" "<<carte._autor<<" "<<carte._editura<<" "<<carte._an<<" "<<carte._nrPagini<<endl;
    return os;
}
void Carte::setTitlu(const string& titlu){
    _titlu = titlu;
}
string Carte::getTitlu() const{
    return _titlu;
}
