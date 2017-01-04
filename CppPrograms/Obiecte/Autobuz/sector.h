#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

#include <iostream>
#include "autobuz.h"
using namespace std;

class sector{
    int _linie;
    int _coloana;

public:
    /**
        Constructorul de conversie de tip.
    */
    sector(const autobuz& aut);
    /**
        Destructorul clasei.
    */
    ~sector(){cout<<"Destructorul a fost apelat."<<endl;}
    /**
        Afiseaza sectorul.
    */
    void Afisare(){
        cout<<"Linia: "<<_linie<<" Coloana: "<<_coloana<<endl;
    }
};

#endif // SECTOR_H_INCLUDED
