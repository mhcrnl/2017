#include <iostream>
#include <iomanip>

using namespace std;

void functie(int a=1, int b=2, int c=3){
    cout<<a<<b<<c<<endl;
}

int main()
{
    cout << "Hello world!" << endl;

    for(int i=0; i< 3 ;i++){
        cout.fill('.');
        cout.width(5+i);
        cout << i<<" "<<endl;
    }
/**
    smanip_long_Cdec1 _FARFUNC setiosflags(long fan);
*/
    cout <<"aliniere la dreapta"<<endl;
    for(int i=0; i< 3 ;i++){
        cout.width(5);
        cout<<setiosflags(ios::right)<<i<<endl;
    }

    cout<<"Aliniere la stanga"<<endl;
    for(int i=0; i< 3 ;i++){
        cout.width(5);
        cout<<setiosflags(ios::left)<<i<<endl;
    }
    /**
        Controlul numarului de cifre in virgula mobila cu cout setprecision
    */
    float valoare=1.2345;
    for(int i=0; i< 8 ;i++){
        cout<<setprecision(i)<<valoare<<'\n';
    }
    float valoare1=0.000123;
    cout<<setiosflags(ios::fixed)<<valoare1<<endl;
    cout<<setiosflags(ios::scientific)<<valoare1<<endl;

    cout<<setbase(8)<<255<<endl;
    cout<<setbase(10)<<255<<endl;
    cout<<setbase(16)<<255<<endl;

    functie();
    functie(9);
    functie(9,8);
    functie(9,8, 7);

    /**
        operatii pe biti cu cout
    */
    unsigned int valoare2, unu =1;
    valoare2=unu<<2;
    cout<<"VALOARE: "<<valoare2<<endl;
    cout<<"REZULTAT: "<<(unu<<2)<<endl;
    cout<<"REZULTAT: fara paranteze "<<unu<<2<<endl;

    enum ZILE {luni, marti, miercuri, joi};
    ZILE zi;
    cout<<zi;

    char *matrice = new char[256];
    for(int i=0; i< 256 ;i++){
        matrice[i]='a';
    }
    //delete[] matrice;
    for(int i=0; i< 256 ;i++){
        cout<<matrice[i]<<i<<' ';
    }

    delete matrice;
/**
    char *pointer;
    do {
        pointer = new char[10];
        if(pointer)
            cout<<"10 octeti alocati."<<endl;
        else
            cout<<"Alocarea memoriei esuate."<<endl;
    }while(pointer);
    cout<<"Alocarea memoriei a avut succes"<<endl;
    */

    int numar = 1;
    int& aliasNumar = numar;
    cout<<"ALIAS: "<<numar<<' '<<aliasNumar+1<<endl;


    return 0;
}
