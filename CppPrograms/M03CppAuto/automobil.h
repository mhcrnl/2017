#ifndef AUTOMOBIL_H_INCLUDED
#define AUTOMOBIL_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Automobil {
    string _model;
    string _nrInmatriculare;
    unsigned int _nrKm; //Km rulati de catre autoturism
    double _consum;

public:
    //Constructorul clasei
    Automobil(string model, string nrInmatriculare, unsigned int nrKm, double consum);
};

#endif // AUTOMOBIL_H_INCLUDED
