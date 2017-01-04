#include <iostream>
#include "avion.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Avion avion;
    avion.creazaAvion();
    avion.afiseaza();

    Avion avion1("Bombardier", "Learjet75", 810, 8);
    avion1.afiseaza();
    cout<<avion1;

    Avion avion2(avion);
    cout<<avion2;
    return 0;
}
