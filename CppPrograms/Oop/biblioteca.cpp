//Nume fisier: biblioteca.cpp
#include "biblioteca.h"
#include <time.h>

void Biblioteca::Adaugare(int codTemporar, char* pTitlu){
    Carte* pCarteNoua=new Carte(codTemporar, pTitlu);
    if(0!=pCarteNoua){
        _listaCarti.push_back(pCarteNoua);
    }
}
Carte* Biblioteca::Cautare(int cod){
    list<Carte*>::iterator iter;
    for(iter=_listaCarti.begin(); iter!=_listaCarti.end(); iter++){
        if((*iter)->CodCarte()==cod){
            return (*iter);
        }
    }
    return 0;
}
void Biblioteca::Catalogare(int codTemporar, int codFinal, char* pCategorie){
    bool terminat=false;
    //Cautam cartea pe care dorim sa o catalogam.
    Carte* pCarte = Cautare(codTemporar);
    if(0!=pCarte){
        terminat = pCarte->Catalogare(codFinal, pCategorie);
    }
    if(!terminat){
        printf("\nCatalogarea a esuat!");
    }
}
void Biblioteca::Imprumutare(int codInventar){
    bool terminat = false;
    //Cautam cartea in lista.
    Carte* pCarte = Cautare(codInventar);
    if(0!=pCarte){
        terminat = pCarte->Imprumutare();
    }
    if(!terminat){
        printf("\nImprumutul nu a fost efectuat.");
    }
}
void Biblioteca::Returnare(int codInventar){
    bool terminat = false;
    //Cautam cartea in lista.
    Carte* pCarte = Cautare(codInventar);
    if(0!=pCarte){
        terminat=pCarte->Returnare();
    }
    if(!terminat){
        printf("\nReturnarea nu a fost efectuata.");
    }
}
void Biblioteca::Inventar(time_t timpInventar){
    list<Carte*>::iterator i;
    //Iteram peste lista de carti.
    for(i=_listaCarti.begin(); i!=_listaCarti.end(); i++){
        (*i)->Inventar(timpInventar);
    }
}
void Biblioteca::Afisare(){
    list<Carte*>::iterator i;
    for(i=_listaCarti.begin(); i!=_listaCarti.end(); i++){
        (*i)->Afisare();
    }
}
