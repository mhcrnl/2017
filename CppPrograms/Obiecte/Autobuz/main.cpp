#include <iostream>
#include "autobuz.h"
using namespace std;
#include "sector.h"

void AfiseazaSectorPeHarta(sector sect){
    cout<<"Afisare harta."<<endl;
    sect.Afisare();
}
int main()
{
    cout << "Hello world!" << endl;

    autobuz autobuz1;
    autobuz1.info();

    autobuz1.urca(12);
    autobuz1.info();

    autobuz1.coboara(5);
    autobuz1.info();

    cout<<autobuz1;
    cin>>autobuz1;

    autobuz1.info();
    //Apel constructorul de copiere
    autobuz autobuz2(autobuz1);
    autobuz2.info();
    //utilizam operatorul de atribuire pt alt autobuz
    autobuz autobuz3 = autobuz2;
    autobuz3.info();
    //scrierea obiectului in fila
    ofstream scriere("autobuz.txt");
    scriere<<autobuz3;
    scriere.close();
    //citirea obiectului din fila
    ifstream citire("autobuz.txt");
    if(citire>>autobuz3){
        cout<<autobuz3<<'\n';
    }
    citire.close();

    autobuz autobuz4(4,7);
    AfiseazaSectorPeHarta(autobuz4);
    return 0;
}
