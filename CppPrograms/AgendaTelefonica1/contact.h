/**
    @file: contact.h
*/
#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//#include "agenda.h"

class Contact{
    string _nume;
    string _prenume;
    string _nrTel;
public:
    void afisare(void);
    Contact(string nume, string prenume, string nrTel);
    //void adauga(void);
    void scrieInFila(const char* fila, const Contact& con);
    string getNrTel(void);
    string getPrenume(void);
    string getNume(void);
    void setNume(string nume);
    friend ostream& operator<<(ostream& os, const Contact& con);
    friend istream& operator>>(istream& is, Contact& con);

    //friend class Agenda;
};


#endif // CONTACT_H_INCLUDED
