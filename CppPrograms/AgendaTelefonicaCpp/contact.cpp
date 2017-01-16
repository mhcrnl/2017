/**
    @project:   AgendaTelefonicaCpp
    @file:      contact.cpp
*/
#include "contact.h"
/**
    1. Constructorul fara parametri.
*/
Contact::Contact(){
    cout<<"Constructorul fara parametri a fost apelat"<<endl;
}
/**
    2. Constructorul cu parametri.
*/
Contact::Contact(string nume, string prenume, string nrTel){
    _nume = nume;
    _prenume = prenume;
    _nrTel = nrTel;
    cout<<"Constructorul cu parametri a fost apelat."<<endl;
}
/**
    4. Constructorul de copiere.
*/
Contact::Contact(const Contact &contact){
    _nume = contact._nume;
    _prenume = contact._prenume;
    _nrTel = contact._nrTel;
    cout<<"Constructorul de copiere a fost apelat."<<endl;
}
/**
    5. operator<<
*/
ostream &operator<<(ostream &output, const Contact &contact){
    output<<"NUME: "<<contact._nume<<"\nPRENUME: "<<contact._prenume
        <<"\nNUMAR TELEFON: "<<contact._nrTel<<endl;
    return output;
}
/**
    6.string getNume()
*/
string Contact::getNume(){ return _nume;}
/**
    7. setNume(string nume)
*/
void Contact::setNume(string nume){
    _nume = nume;
}
/**
    8.
*/
void Contact::setNume(string nume, int lungime){
    int lungNume= nume.length();
    if(lungNume>=lungime){
        cout<<"EROARE: Numele este prea lung!"<<endl;
    }
    cout<<"LUNGIMEA STRINGULUI: "<<lungNume<<endl;
    for(int i=0; i<lungNume; ++i){
        nume.at(i)=toupper(nume.at(i));
    }
    cout<<nume<<endl;
}
