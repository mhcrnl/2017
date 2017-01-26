/**
    @file: agenda.cpp
*/
#include "agenda.h"
int Agenda::index =-1;
void Agenda::adauga(){
    Contact con;
    //if(index==-1){
        index++;
    //}
    cin>>con;
    contacte[index]._nume=con.getNume();
    contacte[index]._prenume=con.getPrenume();
    contacte[index]._nrTel=con.getNrTel();
}
void Agenda::afiseaza(){
    for(int i=0;i<=index; i++){
        cout<<contacte[i].getNume()<<" ";
        cout<<contacte[i].getPrenume()<<" ";
        cout<<contacte[i].getNrTel()<<endl;
    }
}
