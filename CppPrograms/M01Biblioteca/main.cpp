#include <iostream>
#include "carte.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Carte oCarte("Programare C", "Radu Vasile", "Humanitas", 2017, 234);
    //Carte _2Carte;
    oCarte.setTitlu("Ducele");
    cout<<oCarte<<endl;
    //cout<<oCarte<<endl;

    cout<<"Instantele clasei(obiect): "<<oCarte.getNrCrt()<<endl;
    cout<<"Instantele clasei(Carte): "<<Carte::getNrCrt()<<endl;
    //cout<<"Instantele clasei(Carte::_nrCrt): "<<Carte::_nrCrt<<endl; => EROARE este privat

    return 0;
}
