/**
    @file: contact.h
*/
#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <iostream>
#include <string>
#include "persoana.h"
using namespace std;

class Contact:public Persoana{
    string _nrTel;
    string _email;
public:
    Contact();
    Contact( string nume, string nrTel, string email);
};


#endif // CONTACT_H_INCLUDED
