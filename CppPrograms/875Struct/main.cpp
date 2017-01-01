#include <iostream>

using namespace std;

struct Msj{
    char mesaj[256];
    void arataMesaj(void){ cout<<mesaj; }
};

int main()
{
    cout << "Hello world!" << endl;

    Msj carte = {"Totul despre c++"};
    carte.arataMesaj();
    return 0;
}
