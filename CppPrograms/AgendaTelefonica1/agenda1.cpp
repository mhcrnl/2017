/**
    @file: agenda1.cpp
*/
#include "agenda1.h"

void Agenda1::afisare(){
    list<Contact*>::iterator i;
    for(i=_listaContacte.begin(); i !=  _listaContacte.end(); i++){
        (*i)->afisare();
    }
}

void Agenda1::adauga(string nume, string prenume, string nrTel){
    Contact* pContactNou = new Contact(nume, prenume, nrTel);
    if(0 != pContactNou){
        _listaContacte.push_back(pContactNou);
    }

}
