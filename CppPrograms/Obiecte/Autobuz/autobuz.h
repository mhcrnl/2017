//@file autobuz.h
#ifndef AUTOBUZ_H_INCLUDED
#define AUTOBUZ_H_INCLUDED

#include <iostream>
#include <fstream>
using namespace std;

class autobuz{
    int _nrPasageri;
    /**
        Sectorul pe harta unde se ala autobuzul.
    */
    int _linieHarta;
    int _coloanaHarta;
public:
    /**
        Constructor implicit fara parametri.
        Initializeaza obiectele din clasa autobuz
    */
    autobuz();
    /**
        Initializarea unui obiect de tip autobuz.
        Parametrii reprezinta locul unde se afla autobuzul.
    */
    autobuz(int lH, int cH):_linieHarta(lH), _coloanaHarta(cH){}
    /**
        Destructorul clasei autobuz.
    */
    //~autobuz();
    /**
        @return - linia sectorului pe harta unde se afla autobuzul.
    */
    int DaLinieHarta() const {return _linieHarta;}
    /**
        @return Coloana sectorului de pe harta unde se afla autobuzul.
    */
    int DaColoanaHarta() const {return _coloanaHarta;}
    /**
        Constructorul de copiere, realizeaza un duplicat al unui autobuz.
        @param original - referinta catre autobuzul care va fi duplicat.
    */
    autobuz(const autobuz& original);
    /**
        Simuleaza urcarea unui numar de pasageri in autobuz.
        @param nrPasageri - numarul de pasageri care urca.
    */
    void urca(int nrPasageri);
    void coboara(int nrPasageri);
    void info();

    friend ostream& operator<<(ostream& os, const autobuz& aut);

    friend istream& operator>>(istream& is, autobuz& aut);

};


#endif // AUTOBUZ_H_INCLUDED
