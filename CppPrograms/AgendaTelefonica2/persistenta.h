#ifndef PERSISTENTA_H_INCLUDED
#define PERSISTENTA_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "contact.h"

class Contact;

class Persistenta{

public:
    void salveazaInFila( char const* fila,  Contact con);
    void citesteDinFila(char const* fila);
    void salveazaInFila(string fila, Contact con);
    void citesteDinFila(string fila);
};

#endif // PERSISTENTA_H_INCLUDED
