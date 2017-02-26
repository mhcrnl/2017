#include <stdio.h>
#include <stdlib.h>
#define NRMAXELEMENTE 10

void insertLaInceput(){
    int tablou[NRMAXELEMENTE] = {2, 3,4,5};
    int nrElementeActual = 4;
    int i = 0 ;//variabila loop
    int valDeAdaugat = 33;
    //afisarea elementelor actuale
    for (i = 0; i<nrElementeActual; ++i){
        fprintf(stdout, "tablou[%d]=%d\n", i, tablou[i]);
    }
    //shiftarea elementelor cu o pozitie
    for(i = nrElementeActual; i>=0; i--){
        tablou[i+1] = tablou[i];
    }
    // adaugarea elementului pe prima pozitie
    tablou[0] = valDeAdaugat;
    //cresterea numarului de elemente
    nrElementeActual++;
    //afisarea elementelor dupa inserarea pe pozitia 0
    for (i = 0; i<nrElementeActual; ++i){
        fprintf(stdout, "tablou[%d] = %d\n", i, tablou[i]);
    }
}

int main()
{
    printf("Hello world!\n");
    insertLaInceput();
    //Declararea unui tablou vector
    int myArray[] = { 15, 23, 5, 16, 9};
    int nrElemente = 5;
    int noulNrElemente = nrElemente;
    int pozDeAdaugat = 3;
    //Parcurgerea elementelor din vector
    for (int i = 0; i<nrElemente; ++i){
        fprintf(stdout, "%d\n", myArray[i]);
    }
    //Adaugarea unui nou index si cresterea array cu un element
    nrElemente = nrElemente + 1;
    while(noulNrElemente>=pozDeAdaugat){
        myArray[noulNrElemente+1]= myArray[noulNrElemente];
        noulNrElemente = noulNrElemente-1;
    }
    myArray[pozDeAdaugat] = 22;
    //Parcurgerea noului array
    for (int i = 0; i<nrElemente; ++i){
        fprintf(stdout, "%d\n", myArray[i]);
    }

    return 0;
}
