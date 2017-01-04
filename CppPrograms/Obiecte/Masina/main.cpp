#include <iostream>
#include "Masina.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Masina clio("Renault", "Clio", "B64RDD", 20000);
    clio.Afisare();
    clio.setKilometri(19456);
    clio.Afisare();
    cout<<"Numarul de kilometrii parcursi: "<<clio.kmParcursi(19908)<<endl;
    clio.afisareData();
    return 0;
}
