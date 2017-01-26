/**
    @file: controler.cpp
*/
#include "controler.h"
void meniu(){
    cout<<" 'a' . Adauga "<<endl;
    cout<<" 's' . Sterge "<<endl;
    cout<<" 'p' . Afiseaza "<<endl;
    cout<<" 'q' . Quit "<<endl;
}
void Controler::startAplicatie(){
    Agenda agen;
    meniu();
    while(true) {
        char selectie;
        cin>>selectie;
        if(cin.eof()) return;
        switch(selectie){
            case 'a':
                agen.adauga();
                break;
            case 'p':
                agen.afiseaza();
                break;
            case 'q':
                return;
            default:
                cout<<"Selectie invalida."<<endl;
        }
        meniu();
    }
}
