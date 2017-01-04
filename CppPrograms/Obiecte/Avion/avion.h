//Nume fisier: avion.h
#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Avion{
    string _producator;
    string _model;
    int _vitezaMaxima;
    int _nrLocuri;
public:
    /**
        Constructor fara parametrii utilizat la initializarea unui obiect.
    */
    Avion(){}
    /**
        Constructor cu parametrii.
        @param _producator - constructorul aparatului de zbor.
        @param _model - modelul aparatului de zbor.
        @param _vitezaMaxima a aparatului de zbor.
        @param _nrLocuri numarul de locuri ale aparatului de zbor.
    */
    Avion(string prod, string model, int viteza, int locuri);
    /**
        Constructorul de copiere.
    */
    Avion(const Avion& av);
    /**
        Initializeaza datele unui avion.
    */
    void creazaAvion();
    /**
        Afiseaza detaliile avionului.
    */
    void afiseaza();

    friend ostream& operator<<(ostream& os, const Avion& av);
};
#endif // AVION_H_INCLUDED
