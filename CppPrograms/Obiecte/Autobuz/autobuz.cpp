//@file autobuz.cpp
#include "autobuz.h"

autobuz::autobuz():_nrPasageri(0) {}

autobuz::autobuz(const autobuz& original){
    cout<<"Apel la constructorul de copiere."<<endl;
    _nrPasageri = original._nrPasageri;
}

void autobuz::urca(int nrPasageri){
    _nrPasageri += nrPasageri;
}

void autobuz::coboara(int nrPasageri){
    _nrPasageri -= nrPasageri;
}

void autobuz::info(){
    cout<<"NUMARUL DE PASDAGERI: "<<_nrPasageri<<endl;
}

ostream& operator<<(ostream& os, const autobuz& aut){
    os<<aut._nrPasageri<<'\n';
    return os;
}

istream& operator>>(istream& is, autobuz& aut){
    is>>aut._nrPasageri;
    return is;
}
