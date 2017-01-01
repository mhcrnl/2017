#include <iostream>

using namespace std;

struct Msj{
    char mesaj[256];
    void arataMesaj(char *mesaj);
};
/**
    Functie in structura definita in afara structurii
*/
void Msj::arataMesaj(char *mesaj){
    cout<<mesaj;
}
int main()
{
    cout << "Hello world!" << endl;
    Msj carte={"Totul despre c++"};
    carte.arataMesaj(carte.mesaj);

    return 0;
}
