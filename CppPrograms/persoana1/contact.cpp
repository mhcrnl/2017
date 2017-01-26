/**
    @file: contact.cpp
*/
#include "contact.h"

Contact::Contact(string nume, string nrTel, string email):Persoana(nume){
    _nrTel = nrTel;
    _email = email;
}
