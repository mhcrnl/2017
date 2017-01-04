//Nume fila: scfila.h
#include "scfila.h"

void scfila::scrieInFila(char* fila, Avion avion){
    char ch;
    fstream fp;
    fp.open(fila, ios::out|ios::app);
    do{
        fp<<avion;
        cout<<"Doriti sa mai adaugati o intrare(y/n)?: ";
        cin>>ch;
    }while((ch=='y')|(ch=='Y'));
    fp.close();
}
