/**
    @project:   AgendaTelefonicaCpp
    @file:      contact.h
    @author:    Mihai Cornel
    @date:      ianuarie 2017
*/
#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED
/**
    Include:
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/**
    Clasa Contact care are ca scop crearea contactelor.
*/
class Contact {
    string _nume;
    string _prenume;
    string _nrTel;
public:
    /**
       1. Constructorul fara parametrii.
    */
    Contact();
    /**
       2. Constructorul cu parametrii.
        @param - nume contact
        @param - prenume contact
        @param - nrTel contact
    */
    Contact(string nume, string prenume, string nrTel);
    /**
        3. Destructorul clasei Contact este apelat automat la eliminarea
            unui obiect al clasei.
    */
    ~Contact(){cout<<"Destructorul a fost apelat"<<endl;}
    /**
        4. Constructorul de copiere se apeleaza automat ori de cate ori
            este necesara copierea unui obiect al clasei respective. Ex:
            transferul ca parametru intr-o functie.
        @param - const elementul asupra caruia actioneaza nu poate fi
            modificat ulterior. Acesta poate preceda parametrii trimisi
            prin adresa(referinta sau pointer).
    */
    Contact(const Contact &contact);
    /**
        5. Supraincarcarea operatorului ostream operator<<.
    */
    friend ostream &operator<<(ostream &output, const Contact &contact);
    /**
        6. getNume()
    */
    string getNume();
    /**
        7. setNume(string nume)
    */
    void setNume(string nume);
    /**
        8 setNume(string nume, int lungime)
    */
    void setNume(string nume, int lungime);
};


#endif // CONTACT_H_INCLUDED
