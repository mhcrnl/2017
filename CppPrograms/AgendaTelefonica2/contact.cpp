/**
    @file: contact.cpp
*/
#include "contact.h"
/**
    set/get functii
*/
void Contact::setNume(string nume){
    _nume = nume;
}
string Contact::getNume(void){
    return _nume;
}
void Contact::setPrenume(string prenume){
    _prenume= prenume;
}
string Contact::getPrenume(void){
    return _prenume;
}
void Contact::setNrTel(string nrTel){
    _nrTel = nrTel;
}
string Contact::getNrTel(void){
    return _nrTel;
}
/**
    Constructori
*/
Contact::Contact(){
    //cout<<"Constructorul fara parametrii a fost apelat."<<endl;
}
Contact::Contact(string nume, string prenume, string nrTel){
    _nume = nume;
    _prenume = prenume;
    _nrTel = nrTel;
}
/**
    Destructorul
*/
Contact::~Contact(){
    //cout<<"Destructorul a fost apelat."<<endl;
}
istream& operator>>(istream& is, Contact& con){
    cout<<"Introduceti numele/prenumele/numarTelefon(Ex: Mihai Cornel 0722270797): ";
    is>>con._nume>>con._prenume>>con._nrTel;
    return is;
}
ostream& operator<<(ostream& os, const Contact& con){
    os<<con._nume<<" "<<con._prenume<<" "<<con._nrTel;
    return os;
}
