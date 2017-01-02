#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <list>
using namespace std;
#include "carte.h"

class Biblioteca{
private:
    /**
        Vector in care vom memora lista cartilor din biblioteca;
        fiecare element va fi initializat in mod automat prin intermediul
        constructorului clasei Carte
    */
    list<Carte*> _listaCarti;
public:
    /**
        Adauga o carte la lista cartilor bibliotecii.
        Starea cartii va fi PREGATIRE in asteptarea catalogarii;
        @param codTemporar - codul de inventar temporar pt carte
        @param pTitlu - titlul cartii (sir de caractere terminat cu 0)
    */
    void Adaugare(int codTemporar, char* pTitlu);
    /**
        Catalogarea unei carti nou primite.
        @param codTemporar - codul de inventar temporar primit de carte la intrarea in
        biblioteca pana la efectuarea catalogarii
        @param pCategorie - incadrarea cartii intr-o catewgorie in urma catalogarii
    */
    void Catalogare(int codTemporar, int codFinal, char* pCategorie);
    /**
        Imprumutul se poate efectua relativ la o carte care se afla in stare
        DISPONIBILA. In cadrul cartii se memoreaza data imprumutului.
    */
    void Imprumutare(int codInventar);
    /**
        Returnarea se refera la o carte care se afla in starea Imprumutata
        sau Intarziata. dupa terminarea operatiei va reveni in starea DISPONIBILA
    */
    void Returnare(int codInventar);
    /**
        Inventariaza cartile din biblioteca pt a le identifica pe acelea
        a caror returnare a fost intarziata.
        @param time - data si ora efectuarii inventarului
    */
    void Inventar(time_t time);
    /**
        Afiseaza informatii despre toate cartile din lista bibliotecii.
    */
    void Afisare();
private:
    /**
        Cauta in lista de carti o carte cu un cod specificat.
        @param cod - codul cartii cautate
        @return - pointer catre cartea cautata sau 0 daca aceasta nu este gasita
    */
    Carte* Cautare(int cod);
};

#endif // BIBLIOTECA_H_INCLUDED
