#include <iostream>
#include "TelefonMobil.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    //Construirea instantei clasei TelefonMobil
    TelefonMobil unTelefon;
    unTelefon.ModificarePin(1234);
    if(unTelefon.VerificarePin(1234)){
        cout<<"COD pin modificat."<<endl;
    }
    unTelefon.EfectuareApel("0722 34 56 78");
    unTelefon.AcceptareApel("0723 456 789");
    return 0;
}
