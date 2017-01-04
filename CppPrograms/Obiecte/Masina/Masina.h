//Nume fisier: Masina.h
#ifndef MASINA_H_INCLUDED
#define MASINA_H_INCLUDED

#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class Masina{
    string _producator;
    string _model;
    string _numarInmatriculare;
    unsigned int _kilometri;
public:
    /**
        Constructorul clasei Masina.
        @param prod - Producatorul masinii.
        @param model - Modelul masinii.
        @param numar - Numarul de inmatriculare
        @param km - Numarul de kilometrii parcursi
    */
    Masina(string prod, string model, string numar, unsigned int km);
    /**
        Metoda care afiseaza informatiile despre autoturism.
    */
    void Afisare();
    /**
        Metoda care modifica numarul de kilometrii ai masini.
        @param km - Noul numar de kilometrii parcursi;
    */
    void setKilometri(unsigned int km);
    /**
        Metoda calculeaza numarul de km parcursi.
        @param km - numarul de kilometrii
        @return numarul de kilometrii parcursi de la ultima setare.
    */
    int kmParcursi(int km);
    /**
        Afisare data actuala.
    */
    void afisareData();
};


#endif // MASINA_H_INCLUDED
