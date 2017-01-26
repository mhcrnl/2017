#ifndef AGENDA1_H_INCLUDED
#define AGENDA1_H_INCLUDED
#include <iostream>
#include <list>
#include "contact.h"
class Agenda1 {
    list<Contact*> _listaContacte;

public:
    void afisare(void);
    void adauga(string nume, string prenume, string nrTel);
};

#endif // AGENDA1_H_INCLUDED
