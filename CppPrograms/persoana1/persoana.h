/**
    @file: persoana.h
*/
#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Persoana{
    string _nume;
public:
//Constructori:
    Persoana(){};
    Persoana(string nume);
//Destructor:
    ~Persoana();
//Functii de acces:
    void setNume(const string& nume);
    string getNume(void);
//Supraincarcarea operatorilor:
    friend ostream& operator<<(ostream& os, const Persoana& pers);
};

#endif // PERSOANA_H_INCLUDED
