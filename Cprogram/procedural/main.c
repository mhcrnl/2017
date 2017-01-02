#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
    Numarul maxim de carti care poate fi stocat in cadrul bibliotecii
*/
#define NUMAR_MAX_CARTI 100
/**
    Starile posibile in care se poate afla o carte
*/
#define PREGATIRE   1
#define DISPONIBILA 2
#define IMPRUMUTATA 3
#define INTARZIATA  4
/**
    Numarul de secunde care reprezinta 14 zile. Dupa 14 zile cartile
    nereturnate trec in starea INTARZIATA.
*/
#define SECUNDE_IN_14_ZILE (14*24*60*60)
/**
    Prima pozitie nu este utilizata deoarece 0 nu este un cod de stare valid
*/
char* DENUMIRE_STARI[]={
    "",
    "PREGATIRE",
    "DISPONIBILA",
    "IMPRUMUTATA",
    "INTARZIATA"
};
/**
    Structura utilizata pentru a reprezenta informatiile despre o carte
*/
struct CARTE{
    int _cod; //codul de inventar al cartii
    char* _titlu;
    char* _categorie; //categoria din care face parte cartea
    int _stare; //Starea (situatia cartii
    time_t _dataImprumut; // data la care cartea a fost ultima data imprumutata
};
/**
    Vector in care vom memora lista cartilor din biblioteca
*/
struct CARTE ListaCarti[NUMAR_MAX_CARTI];
/**
    Numarul curent de carti in biblioteca. Indica de asemenea si
    prima pozitie libera in vectorul ListaCarti
*/
int NrCartiInBiblioteca =0;
/**
    Initializeaza lista de carti a bibliotecii. Toate codurile pentru
    elementele vectorului ListaCarti vor fi setate la valoarea 0. Similar
    titlurile si categoriile vor primi ca valore sirul vid "".
*/
void Initializare(){
    int i;
    for(i=0; i<NUMAR_MAX_CARTI; ++i){
        ListaCarti[i]._cod = 0;
        ListaCarti[i]._titlu = "";
        ListaCarti[i]._categorie = "";
        ListaCarti[i]._stare = 0;
        ListaCarti[i]._dataImprumut = 0;
    }
    NrCartiInBiblioteca =0;
}
/**
    Adauga o carte la lista cartilor bibliotecii.
    Starea cartii va fi PREGATIRE in asteptarea catalogarii.
    @param codTemporar reprezinta codul de inventar temporar pt. carte.
    @param pTitlu este titlul cartii(sir de caractere terminat cu 0).
*/
void Adaugare(int codTemporar, char* pTitlu){
    ListaCarti[NrCartiInBiblioteca]._cod = codTemporar;
    ListaCarti[NrCartiInBiblioteca]._titlu = pTitlu;
    ListaCarti[NrCartiInBiblioteca]._categorie = "";
    ListaCarti[NrCartiInBiblioteca]._stare = PREGATIRE;
    //Numarul de carti in biblioteca creste cu 1
    ++NrCartiInBiblioteca;
}
/**
    Cauta in lista de carti o carte cu un cod specificat.
    @param cod este codul cartii cautate.
    @return indexul elementului din vector unde este stocata
    cartea sau -1 daca nu este gasita.
*/
int Cautare(int cod){
    int index;
    for(index=0; (index<NrCartiInBiblioteca)&&(ListaCarti[index]._cod!= cod); ++index);
    if(NrCartiInBiblioteca==index){
        index=-1;
    }
    return index;
}
/**
    Catalogarea unei carti nou primite
    @param codTemporar retine codul de inventar temporar primit de carte la intrarea in
    biblioteca pana la efectuarea catalogarii.
    @param codFinal e codul de inventar final asociat cartii in urma catalogarii.
    @param pCategorie retine incadrarea cartii intr-o categorie in urma catalogarii.
*/
void Catalogare(int codTemporar, int codFinal, char* pCategorie){
    int terminat =0;
    //Cautam pozitia cartii pe care dorim sa o catalogam.
    int pozitie = Cautare(codTemporar);
    if(-1!=pozitie){
        //Cartea trebuie sa fie in starea PREGATIRE.
        if(PREGATIRE == ListaCarti[pozitie]._stare){
            ListaCarti[pozitie]._cod = codFinal;
            ListaCarti[pozitie]._categorie = pCategorie;
            ListaCarti[pozitie]._stare = DISPONIBILA;
            terminat = 1;
        }
    }
    if(!terminat){
        printf("\nCatalogarea a esuat!");
    }
}
/**
    Imprumuta o carte la un client. Cartea trebuie sa fie in starea DISPONIBILA
    si va trece in starea IMPRUMUTATA.
    @param codInventar retine codul cartii imprumutate
*/
void Imprumutare (int codInventar){
    int terminat=0;
    //Cautam pozitia cartii in lista
    int pozitie = Cautare(codInventar);
    if(-1!=pozitie){
        //Cartea trebuie sa fie in starea DISPONIBILA pt. a fi imprumutata.
        if(DISPONIBILA == ListaCarti[pozitie]._stare){
            ListaCarti[pozitie]._stare = IMPRUMUTATA;
            /**
                Memoram data la care a fost realizat imprumutul. Functia din
                biblioteca standard time furnizeaza timpul trecut in secunde de la 1 ianuarie 1970.
            */
            time(&(ListaCarti[pozitie]._dataImprumut));
            terminat =1;
        }
    }
    if(!terminat){
        printf("\nImprumutul nu a fost efectuat.");
    }
}
/**
    Implementeaza procesarile care trebuie efectuate la returnarea unei carti de catre un cititor.
    @param codInventar - codul cartii care este returnata.
*/
void Returnare(int codInventar){
    int terminat=0;
    //Cautam pozitia cartii in lista
    int pozitie = Cautare(codInventar);
    if(-1!=pozitie){
        //Carte trebuie sa fie in una din starile IMPRUMUTATA sau INTARZIATA
        if((IMPRUMUTATA==ListaCarti[pozitie]._stare)||(INTARZIATA==ListaCarti[pozitie]._stare)){
            ListaCarti[pozitie]._stare =DISPONIBILA;
            terminat = 1;
        }
    }
    if(!terminat){
        printf("\nReturnarea nu a fost efectuata");
    }
}
/**
    Inventariaza cartile din biblioteca pentru a le identifica pe acelea a caror returnare a fost intarziata.
    @param time - data si ora efectuarii inventarului.
*/
void Inventar(time_t time){
    int i;
    //Pentru fiecare carte existenta in biblioteca
    for(i=0; i<NrCartiInBiblioteca; ++i){
        //Daca o carte este IMPRUMUTATA
        if(IMPRUMUTATA==ListaCarti[i]._stare){
            //calculam numarul de zile de la data imprumutului.
            time_t durataImprumut = time - ListaCarti[i]._dataImprumut;
            if(durataImprumut>SECUNDE_IN_14_ZILE){
                //Cartea este imprumutata de mai mult de 14 zile.
                ListaCarti[i]._stare = INTARZIATA;
            }
        }
    }
}
/**
    Numarul de caractere necesare pentru a reprezenta o data calendaristica.
*/
#define DIM_DATA 26
/**
    Afiseaza informatii despre toate cartile din lista bibliotecii.
*/
void Afisare(){
    int i;
    //Tiparim informatiile despre fiecare carte.
    for(i=0; i<NrCartiInBiblioteca; ++i){
        char data[DIM_DATA];
        //ctime_s(data,DIM_DATA, &(ListaCarti[i]._dataImprumut));
        printf("\nCOD:                  %d", ListaCarti[i]._cod);
        printf("\nTITLU:                %s", ListaCarti[i]._titlu);
        printf("\nCATEGORIE:            %s", ListaCarti[i]._categorie);
        printf("\nSTARE:                %s",DENUMIRE_STARI[ ListaCarti[i]._stare]);
        printf("\nDATA IMPRUMUT:        %s", data);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    printf("Hello world!\n");
    //La inceputul executiei initializam lista de carti utilizata de program
    Initializare();
    //Adaugam carti in biblioteca
    Adaugare(1, "dune");
    Adaugare(2, "Istoria Frantei");
    //Afisare informatii carti
    Afisare();
    //Catalogam cartile nou primite
    Catalogare(1, 1002, "Istorie");
    Catalogare(2, 1001, "S.F.");
    Afisare();
    //Imprumutam o carte.
    Imprumutare(1002);
    Afisare();
    //Efectuam inventarul peste 28 de zile.
    Inventar(time(0)+2*SECUNDE_IN_14_ZILE);
    Afisare();
    //Cartea imprumutata este returnata.
    Returnare(1002);
    Afisare();
    return 0;
}
