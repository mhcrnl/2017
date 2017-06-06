#include <stdio.h>
#include <stdlib.h>
//Declararea functiilor
int fibonacci(int nr);
void afisare_array(int arr[],int nr);
void save_to_file(const char* filename, const char* mode, int nr);
void read_from_file(const char* filename, const char* mode);
void copiere(int nr);
//Variabilele
int fibo_array[30];
int fibo_copie[30];
FILE *fp;
// Definirea functiilor
void copiere(int nr){
    int i;
    for(i=0; i<nr; i++){
        fibo_copie[i] = fibo_array[i];
    }
    printf("Copiere array cu succes!");
}
void read_from_file(const char* filename, const char* mode){
    //char buff[255];
    char ch;
    fp = fopen(filename, mode);
    //fgets(buff, 255, (FILE*)fp);
    while((ch=fgetc(fp))!= EOF){
        printf("%c", ch);
    }

    fclose(fp);
}
void save_to_file(const char* filename, const char* mode, int nr){
   int i;
   fp = fopen(filename, mode);
   for(i=0; i<nr; i++){
        fprintf(fp, "Fibonacci[%d]=%d\n", i, fibo_array[i]);
   }
   fclose(fp);
}
int fibonacci(int nr){
    //Functia Fibonacci cu recursivitate
    if (nr == 0){
        return 0;
    }else if(nr == 1){
        return 1;
    } else {
        return fibonacci(nr-1)+fibonacci(nr-2);
    }
}
void afisare_array(int arr[],int nr){
    // Afisarea numerelor din array
    int i;
    for(i =0; i<nr; i++){
        printf("Tablou[%d]= %d\n", i, arr[i]);
    }
}
int main()
{
    int nr; //numarul de numere Fibonacii
    int i; //utilizat in for

    printf("Hello world!\n");
    printf("Introduceti numarul de numere Fibonacci de generat:");
    scanf("%d", &nr);
    for(i=0; i<nr; i++){
        printf("Numerele %d Fibonacii %d\n", i, fibonacci(i));
        fibo_array[i]= fibonacci(i);
    }
    afisare_array(fibo_array,30);
    save_to_file("fibonacci.txt", "w", 30);
    read_from_file("fibonacci.txt", "r");
    copiere(30);
    afisare_array(fibo_copie, 30);
    return 0;
}
