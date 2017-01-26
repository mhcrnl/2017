/**
    @file: agenda.cpp
*/
#include "agenda.h"

int Agenda::index=-1;

void Agenda::adauga(void){
    fstream fp;
    Contact con;
    index = incarcaContacte();
    if(index==-1) index++;
    cin>>con;
    fp.open("contacte.txt", ios::out);
    contacte[index]->getNume();
    contacte[index]->getPrenume();
    contacte[index]->getNrTel();
    for(int i=0; i<=index; i++){
        fp<<con<<endl;
    }
    fp.close();
}

int Agenda::incarcaContacte(void){
    Contact con;
    int i=-1;
    fstream fp;
    fp.open("contact.txt", ios::in);
    if(fp.fail()){
        cout<<"LISTA DE CONTACTE ESTE GOALA."<<endl;
    } else {
        while(!fp.eof()){
            i++;
            fp>>con;
            contacte[i]->getNume();
            contacte[i]->getPrenume();
            contacte[i]->getNrTel();
        }
    }
    fp.close();
    return i;
}
