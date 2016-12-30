#include <iostream>
#include <stdio.h>

using namespace std;
int nume_global = 1001;
int main()
{
    cout << "Hello world!" << endl;
    cout << "Valoarea decimala: " <<dec<<0xFF<< endl;
    cout<<"Valoarea octala "<<oct<<10<<endl;
    cout<<"valoarea hexadecimala"<<hex<<255<<endl;

    for(int i=0; i<100; i++)
        cout<<dec<<i<<"\n ";
    printf("Aceasta linie utilizeaza printf()");

    /**Reditrectare cerr*/
    for(int i=0; i<100; i++)
        cerr<<"Nuse poate redirecta cer "<<i<<'\n';

    int varsta;
    float salariu;
    char nume[129];
    cout<<"Introduce-ti numele dvs, varsta si salariul: "<<endl;
    cin>>nume>>varsta>>salariu;
    cout<<nume<<' '<<varsta<<' '<<salariu<<' ';

    clog<<"O eroare ciudata de programare<<";

    cout<<"Acest text apare imediat"<<flush;

    /**Uniuni anonime*/
    union{
        int datele_mele;
        float datele_lui;
    };
    datele_mele =3;
    cout<<"Valoarea datelor_mele este: "<<datele_mele<<endl;
    datele_lui=123.345;
    cout<<"Valoarea ddatelor_lui este: "<<datele_lui<<endl;

    int nume_global=1; //variabila locala
    cout<<"Valoarea variabilei locale: "<<nume_global<<endl;
    cout<<"Valoarea variabilei global: "<<::nume_global<<endl;
    return 0;
}
