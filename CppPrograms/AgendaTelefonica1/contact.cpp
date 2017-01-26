/**
    @file: contact.cpp
*/
#include "contact.h"

Contact::Contact( string nume, string prenume, string nrTel){
    _nume = nume;
    _prenume = prenume;
    _nrTel = nrTel;
}

void Contact::afisare(void){
    cout<<_nume<<" "<<_prenume<<" "<<_nrTel<<endl;
}

void Contact::scrieInFila(const char* fila, const Contact& con){
    ofstream pf(fila, ios::app);
    if(pf.is_open()){
        pf<<con<<endl;
        pf.close();
    } else {
        cout<<"FILA nu a fost deschisa."<<endl;
    }
}

string Contact::getNrTel(void){
    return _nrTel;
}

string Contact::getPrenume(void){
    return _prenume;
}

string Contact::getNume(void){
    return _nume;
}

ostream& operator<<(ostream& os, const Contact& con){
    os<<"Nume...........: "<<con._nume<<endl
      <<"Prenume........: "<<con._prenume<<endl
      <<"Numar Telefon..: "<<con._nrTel<<endl;
      return os;
}

istream& operator>>(istream& is, Contact& con){
    cout<<"Introduceti Numele Prenumele NumarTelefon:(Ex:Mihai Cornel 0722270796)"<<endl;
    is>>con._nume >>con._prenume >> con._nrTel;
    return is;
}
