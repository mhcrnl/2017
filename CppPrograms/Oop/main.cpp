//Nume fisier main.cpp
#include <iostream>
#include "biblioteca.h"
using namespace std;

int main()
{
    cout << "Hello world!BIBLIOTECA" << endl;

    Biblioteca b;
    //Adaugam carti in bilblioteca.
    b.Adaugare(1, "Dune");
    b.Adaugare(2, "Istoria Frantei");
    //Afisare informatii carti
    b.Afisare();
    //Catalogam cartile nou primite.
    b.Catalogare(2, 1002, "Istorie");
    b.Catalogare(1, 1001, "S.F.");
    b.Afisare();
    //Imprumutam o carte
    b.Imprumutare(1002);
    b.Afisare();
    //Efectuam inventarul peste 28 de zile.
    b.Inventar(time(0)+2*SECUNDE_IN_14_ZILE);
    b.Afisare();
    //Cartea imprumutata este returnata.
    b.Returnare(1002);
    b.Afisare();
    return 0;
}
