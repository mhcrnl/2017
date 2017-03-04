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
    Automobil(string model="", string nrInmatriculare="", unsigned int nrKm=0, double consum=0.0);
    //supraincarcarea operatorului operator<<
    friend ostream& operator<<(ostream& os, Automobil const& aut);
    //functie membra a clasei care calculeaza consumul total in functie de km si consum
    double consumCarburant() const;
    double costTotalCarburant(double pretLitru) const;

    void setModel(string const& model);
    string getModel() const;
};

#endif // AUTOMOBIL_H_INCLUDED
