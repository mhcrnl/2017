//Nume fisier: carte.cpp
#include "carte.h"
#include <stdio.h>

/**
    Pointeri catre obiecte care reprezinta starile:
    Pregatire, Disponibila, Imprumutata, Intarziata
*/
extern Pregatire* PREGATIRE;
extern Disponibila* DISPONIBILA;
extern Imprumutata* IMPRUMUTATA;
extern Intarziata* INTARZIATA;

Carte::Carte(int cod, char* pTitlu){
    _cod = cod;
    _pTitlu=pTitlu;
    _pStare = PREGATIRE;
    _pCategorie="";
    _dataImprumut =0;
}
void Carte::ModificaStare(Stare* pStareNoua){
    _pStare=pStareNoua;
}
bool Carte::Catalogare(int codFinal, char* pCategorie){
    bool status =_pStare->Catalogare(this);
    if(status){
        _cod=codFinal;
        _pCategorie=pCategorie;
    }
    return status;
}
bool Carte::Imprumutare(){
    bool status=_pStare->Imprumutare(this);
    if(status){
        //Daca operatia de imprumut a reusit, atunci retine data imprumutului
        time(&_dataImprumut);
    }
    return status;
}
bool Carte::Returnare(){ return _pStare->Returnare(this);}
void Carte::Inventar(time_t timpInventar){_pStare->Inventar(this, timpInventar);}
void Carte::Afisare(){
    //Afisam informatiile despre carte
    char data[DIM_DATA];
    //ctime_s(data, DIM_DATA, &_dataImprumut);
    printf("\nCOD:                        %d", _cod);
    printf("\nTITLU:                      %s", _pTitlu);
    printf("\nCATEGORIE:                  %s", _pCategorie);
    printf("\nSTARE:                      %s", _pStare->DenumireStare());
    printf("\nDATA IMPRUMUT:              %s", data);
    printf("\n");
}
