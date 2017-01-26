/**
    @file: persoana.cpp
*/
#include "persoana.h"
/**
    Definire si initializare membrului static nrCrt se
    realizeaza in afara clasei.
*/
int Persoana::_nrCrt = 0;

Persoana::Persoana(){
    _nume = setNume();
    _prenume= setPrenume();
    _nrCrt++;
}
Persoana::Persoana(string nume, string prenume){
    _nume = nume;
    _prenume = prenume;
}

string Persoana::setNume(){
    string nume;
    cout<<"Introduceti numele persoanei: ";
    cin>>nume;
    return nume;
}

string Persoana::getNume(){
    return _nume;
}

string Persoana::setPrenume(){
    string prenume;
    cout<<"Introduceti prenumele persoanei: ";
    cin>>prenume;
    return prenume;
}

string Persoana::getPrenume(){
    return _prenume;
}

int Persoana::getNrCrt(){
    return Persoana::_nrCrt;
}

ostream& operator<<(ostream& os, const Persoana& pers){
    os<<Persoana::_nrCrt<<" "<<pers._nume<<" "<<pers._prenume;
    return os;
}
