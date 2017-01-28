/**
    @file: controler.cpp
*/
#include "controler.h"
#include "readme.h"
class Contact;

void meniu(){
    cout<<" 'a' . Adauga "<<endl;
    cout<<" 's' . Salveaza in fila. "<<endl;
    cout<<" 'c' . Citeste din fila. "<<endl;
    cout<<" 'p' . Afiseaza "<<endl;
    cout<<" 'r' . Creaza fila README.md "<<endl;
    cout<<" 'q' . Quit "<<endl;
}
void Controler::startAplicatie(){
    Agenda agen;
    Persistenta persistenta;
    char const* fila = "contacte.txt";
    string fila1 = "contacte1.txt";
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
            case 's':
                {

                Contact conta;
                conta.setNume("Mihai");
                conta.setPrenume("Cornel");
                conta.setNrTel("0722270796");
                //conta("Mihai", "Cornel", "0722270796");
                persistenta.salveazaInFila(fila, conta);
                persistenta.salveazaInFila(fila1, conta);
                break;
                }
            case 'c':
                persistenta.citesteDinFila(fila);
                persistenta.citesteDinFila(fila1);
                break;
            case 'r':
                {
                    CreazaReadme cr;
                    cr.readme();
                    break;
                }
            case 'q':
                return;
            default:
                cout<<"Selectie invalida."<<endl;
        }
        meniu();
    }
}
