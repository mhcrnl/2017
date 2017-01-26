#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Persoana{
    string _nume;
public:
    Persoana(string nume);

    friend ostream& operator<<(ostream& is, const Persoana& pers);
};

#endif // PERSOANA_H_INCLUDED
