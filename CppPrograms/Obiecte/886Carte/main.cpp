#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Carte{
public:
    char titlu[256];
    char autor[64];
    float pret;

    void arataTitlu(void){cout<<titlu<<endl;}
    float Pret(void){return pret; }
};

int main()
{
    cout << "Hello world!" << endl;

    Carte unu;
    strcpy(unu.titlu,"Totul despre c si c++");
    strcpy(unu.autor,"Mihai Cornel");
    unu.pret = 49.67;
    unu.arataTitlu();
    cout<<"Pretul carti este: "<<setprecision(4)<<unu.Pret()<<endl;
    return 0;
}
