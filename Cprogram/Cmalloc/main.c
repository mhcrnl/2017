#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world! Utilizarea functiei malloc.\n");

    int *ptr;
    ptr = (int*)malloc(sizeof(int));
    if(ptr!=NULL){
        *ptr = 200;
        printf("ptr pointeaza catre valoarea %d", *ptr);
        free(ptr);
    } else {
        printf("Alocarea memoriei a esuat.");
    }
    return 0;
}
