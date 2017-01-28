#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <iostream>
#include <string>
#include <locale> //locale, toupper
#include <algorithm>
using namespace std;

class Agenda;

class Contact{
    string _nume;
    string _prenume;
    string _nrTel;
public:
    /**
        set/get functions.
    */
    void setNume(string nume);
    string getNume(void);
    void setPrenume(string prenume);
    string getPrenume(void);
    void setNrTel(string nume);
    string getNrTel(void);
    /**
        Constructori
    */
    Contact();
    Contact(string nume, string prenume, string nrTel);
    /**
        Destructorul
    */
    ~Contact();
    /**
        Clasa prietena
    */
    friend class Agenda;
    /**
        Supraincarcarea operatorilor
    */
    friend istream& operator>>(istream& is, Contact& con);
    friend ostream& operator<<(ostream& os, const Contact& con);
};

#endif // CONTACT_H_INCLUDED
