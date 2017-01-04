//Nume fila: scfila.h
#ifndef SCFILA_H_INCLUDED
#define SCFILA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "avion.h"
/**
    Clasa care scrie si citeste intro fila un anumit tip de obiect.
*/
class scfila{

public:
    /**
        Metoda de scriere in fila a datelor de tip avion.
        @param fila - numele filei in care se va scrie datele.
        @param avion - datele din clasa avion ce vor fi scrise in fila.
    */
    void scrieInFila(char* fila, Avion avion);

};

#endif // SCFILA_H_INCLUDED
