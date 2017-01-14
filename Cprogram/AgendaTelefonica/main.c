/**
    @file: main.c
    @author: Mihai Cornel
    @date: 14.01.2017
    @project: AgendaTelefonica in C.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
    Directive preprocesor.
*/
#define STRADA 50
#define ORAS 30
#define NUME 30
#define EMAIL 50
//Definirea valorii numarului maxim acceptat intr-un vector.
#define NUMAR_MAX_CONTACTE 1000
/**
    Structura de date care inglobeaza numele strazii, numarul si orasul.
*/
typedef struct ADRESA{
    char* strada;
    int nrStrada;
    char* oras;
}ADRESA;
/**
    Structura de date care este utilizata pt. pastrarea datelor unui contact.
*/
typedef struct CONTACT {
    long long int nrTel;
    char* nume;
    char* prenume;
    char* email;
    ADRESA adresa;
}CONTACT;
/**
    Vectorul(array) in care vom memora lista contactelor din agenda telefonica.
*/
struct CONTACT ListaContacte[NUMAR_MAX_CONTACTE];
/**
    Numarul curent de contacte in agenda. Indica de asemenea si prima pozitie
    libera in vectorul ListaContacte.
*/
int NrContacteInAgenda = 0;
/**
    ----------------------------PROTOTIPUL FUNCTIILOR ----------------------
    1. Initializare() - initializeaza lista de contacte. Toate codurile pentru
    elementele vectorului ListaContacte vor fi setate la valoarea 0. Similar
    titlurile si categoriile vor primi ca valoare sirul vid "".
    Initializarea automata a structurilor de date la momentul crearii contrubuie
    la crsterea calitatii aplicatiilor si evitarea erorilor de programare.
*/
void Initializare(void);
/**
    2. Adaugare
*/
void Adaugare(long long int nrTel, char* nume, char* prenume);
/**
    3. Afisare
*/
void Afisare(void);
/**
    4. getNume -couta in lista dupa numele contactului
*/
int getNume(char* nume);
/**
    5. Meniu()- optiunile aplicatiei intr-o functie.
*/
void Meniu(void);
/**
    -------------------------------MAIN------------------------------------
*/
int main()
{
    printf("Hello world! Agenda Telefonica in C - programare procedurala.\n");
    Initializare();
    Meniu();
    Adaugare(722270796, "Mihai", "Cornel");
    Adaugare(723319664, "Alexandru", "Adrian");
    Afisare();
    printf("CONTACT: %d\n", getNume("Mihai"));
    printf("CONTACT: %d", getNume("Vasile"));
    return 0;
}

/**
    1. void Initializare (void)
*/
void Initializare(){
    int i;
    for(i=0; i<NUMAR_MAX_CONTACTE; ++i){
        ListaContacte[i].nrTel = 0;
        ListaContacte[i].nume = "";
        ListaContacte[i].prenume = "";
        ListaContacte[i].email = "";
        ListaContacte[i].adresa.nrStrada = 0;
        ListaContacte[i].adresa.strada = "";
        ListaContacte[i].adresa.oras = " ";
    }
    NrContacteInAgenda = 0;
}
/**
    2. void Adaugare(nrTel, nume, prenume);
*/
void Adaugare(long long int nrTel, char* nume, char* prenume){
    ListaContacte[NrContacteInAgenda].nrTel = nrTel;
    ListaContacte[NrContacteInAgenda].nume = nume;
    ListaContacte[NrContacteInAgenda].prenume = prenume;
    //Numarul de contacte in agenda creste cu unu.
    ++NrContacteInAgenda;
}
/**
    3. void Afisare(void);
*/
void Afisare(void){
    int i;
    for(i=0; i<NrContacteInAgenda; ++i){
        //warning: too many arguments for format %lld
        printf("\nNUMAR TELEFON:        %lld", ListaContacte[i].nrTel);
        printf("\nNUME:                 %s", ListaContacte[i].nume);
        printf("\nPRENUME:              %s", ListaContacte[i].prenume);
        printf("\nEMAIL:                %s", ListaContacte[i].email);
        printf("\nSTRADA:               %s", ListaContacte[i].adresa.strada);
        printf("\nNUMAR STRADA:         %d", ListaContacte[i].adresa.nrStrada);
        printf("\nORAS:                 %s\n", ListaContacte[i].adresa.oras);
    }
}
/**
    4. void getNume(LisataContacte lista, char nume);
*/
int getNume(char* nume){
    int i;
    for(i=0; i<NrContacteInAgenda; ++i){
        if(ListaContacte[i].nume == nume){
            return 1;
        }
    }
    return 0;
}
/**
    5. void Meniu(void)
*/
void Meniu(void){
    printf("_______________Meniul Agendei Telefonice_______________\n");
    printf("1. Adaugare Contact.  \n");
    printf("2. Cautare Contact.  \n");
    printf("3. Modificare Contact.\n");
}
