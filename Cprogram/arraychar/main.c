#include <stdio.h>
#include <stdlib.h>
//#include <iostream>

//using namespace std;

int main()
{
    printf("Hello world!\n");

    char s[10] = "ABCDE", *p=s+3;
    printf("%c\n", *p);
    printf("p[1]=%c\n", p[1]);
    printf("p[-1]=%c\n", p[-1]);
    printf("%d\n", p[1]-p[-1]);
    printf("s[1]=%c\n", s[1]);
    printf("s[-1]=%c\n", s[-1]);// este zero sou o memorie fara acoperirer
    printf("%d", s[1]-s[-1]);
/** afisarea hexadecimal si octal in c si c++*/
    //cout<<"Valoarea zecimala"<< dec<<0xFF;

    return 0;
}
