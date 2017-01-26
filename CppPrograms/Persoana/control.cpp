/**
    @file: control.cpp
*/
#include "control.h"

void meniu(){
    cout<<"------------Meniu Aplicatie---------------"<<endl;
    cout<<" 1. Adauga persoana-----------------------"<<endl;
    cout<<" 2. Sterge persoana-----------------------"<<endl;
    cout<<" 3. Afisare persoane----------------------"<<endl;
    cout<<" 4. Exit program--------------------------"<<endl;
    cout<< "Introduceti optiunea dumneavoastra: " ;
}

void control(){
    int optiune;
    do {
        meniu();
        cin>>optiune;
        switch(optiune){
        case 1:

            adaugareInLista();
            break;

        case 2:

            break;
        case 3:
            afisare();
            break;
        case 4:
            exit(0);
        default:
            cout<<"Meniu";
        }
    } while(optiune != 4);
}

void adaugareInLista(){
    if(nrPersoaneInLista == NUMAR){
        cout<<"LIsta de persoane este plina!"<<endl;
        return;
    }
    Persoana pers;
    pers.getNume();
    pers.getPrenume();

    listaPersoane1[nrPersoaneInLista] = pers;
    //listaPersoane[nrPersoaneInLista].getPrenume();
    ++nrPersoaneInLista;
}

void afisare(){
    for(int i = nrPersoaneInLista-1;i>=0; i-- ){
        cout<<listaPersoane1[i].getNume()<<endl;
    }
}
