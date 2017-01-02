// Nume fisier: stare.cpp
#include "stare.h"
#include "carte.h"

static Pregatire STARE_PREGATIRE;
static Disponibila STARE_DISPONIBILA;
static Imprumutata STARE_IMPRUMUTATA;
static Intarziata STARE_INTARZIATA;
//Pointeri catre starile posibile ala unei carti
Pregatire* PREGATIRE = &STARE_PREGATIRE;
Disponibila* DISPONIBILA = &STARE_DISPONIBILA;
Imprumutata* IMPRUMUTATA = &STARE_IMPRUMUTATA;
Intarziata* INTARZIATA = &STARE_INTARZIATA;

bool Stare::Catalogare(Carte* pCarte){return false;}
bool Stare::Imprumutare(Carte* pCarte){return false;}
bool Stare::Returnare(Carte* pCarte){return false;}
void Stare::Inventar(Carte* pCarte, time_t timpInventar){}
bool Pregatire::Catalogare(Carte* pCarte){
    pCarte->ModificaStare(DISPONIBILA);
    return true;
}
bool Disponibila::Imprumutare(Carte* pCarte){
    pCarte->ModificaStare(IMPRUMUTATA);
    return true;
}
void Imprumutata::Inventar(Carte* pCarte, time_t timpInventar){
    time_t durataImprumut = timpInventar - pCarte->DataImprumut();
    if(durataImprumut>SECUNDE_IN_14_ZILE){
        pCarte->ModificaStare(INTARZIATA);
    }
}
bool Imprumutata::Returnare(Carte* pCarte){
    pCarte->ModificaStare(DISPONIBILA);
    return true;
}
bool Intarziata::Returnare(Carte* pCarte){
    pCarte->ModificaStare(DISPONIBILA);
    return true;
}
