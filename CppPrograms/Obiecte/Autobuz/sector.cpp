//@file sector.cpp
#include "sector.h"

sector::sector(const autobuz& aut){
    cout<<"Constructorul de conversie."<<endl;
    _linie=aut.DaLinieHarta();
    _coloana=aut.DaColoanaHarta();
}
