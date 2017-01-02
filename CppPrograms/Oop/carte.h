#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include "stare.h"
/**
    Clasa utilizata pt. a reprezenta informatiile despre o carte.
*/
class Carte{
    /**
        Numarul de caractere necesare pt. a reprezenta o data calendaristica
        (constanta intreaga).
    */
    static const int DIM_DATA=26;
private:
    //codul de inventar al cartii
    int _cod;
    char* _pTitlu;
    //Categoria din care face parte cartea
    char* _pCategorie;
    //Starea (situatia) cartii
    Stare* _pStare;
    //Data la care cartea a fost ultima data imprumutata
    time_t _dataImprumut;
public:
    //Initializarea unui obiect de tip carte.
    Carte(int cod, char* pTitlu);
    /**
        @return Codul de inventar al cartii
    */
    int CodCarte() { return _cod; }
    //@return - data ultimului imprumut
    time_t DataImprumut(){return _dataImprumut;}
    /**
        Executa operatia de catalogare a cartii.
        @param codFinal - codul final asociat cartii in urma catalogarii
        @param pCategorie - sir de caractere terminat cu zero reprezentand
        categoria asociata prin catalogare.
        @return true daca operatia de catalogare a fost incheiata cu succes
        si false altfel
    */
    bool Catalogare(int codFinal, char* pCategorie);
    /**
        I se imprumuta cartea unui cititor.
        @return true daca operatia de imprumut s-a desfasurat cu succes sau false altfel
    */
    bool Imprumutare();
    /**
        Cititorul returneaza cartea.
        @return true daca operatia de returnare a avut succes si false altfel
    */
    bool Returnare();
    /**
        Se aplica procedura de inventar a cartii.
        @param timpInventar - data efectuarii inventarului.
    */
    void Inventar(time_t timpInventar);
    /**
        Se afiseaza informatiile despre carte.
    */
    void Afisare();
    /**
        Modifica starea cartii.
        @param pStareNoua - noua stare a cartii.
    */
    void ModificaStare(Stare* pStareNoua);
};
#endif // CARTE_H_INCLUDED
