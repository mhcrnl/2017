#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class Persoana{
    string _nume;
    string _prenume;

public:
    /**
        O clasa poate contine membrii statici(date si functii).
        Referirea din afara clasei se poate face in doua feluri:
        1. NumeObiect.NumeMembruStatic;
        2. NumeClasa::NumeMembruStatic;//Membrii statici sunt aceiasi
        pt. toate obiectele clasei.
    */
    static int _nrCrt;
    /**
        Constructori
    */
    Persoana();
    Persoana(string nume, string prenume);
    /**
        Destructor
    */
    ~Persoana() { _nrCrt--; }
    /**
        Get-eri/ set-eri
    */
    string setNume();
    string getNume();
    string setPrenume();
    string getPrenume();
    /**
        Functiile membre statice efectueaza operatii care nu sunt asociate
        obiectelor individuale, ci intregii clase, acestea nu se pot
        referi la this.
    */
    static int getNrCrt();
    /**
        Supraincarcarea operatorilor.
    */
    friend ostream& operator<<(ostream& os, const Persoana& pers);
};


#endif // PERSOANA_H_INCLUDED
