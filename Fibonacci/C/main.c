//Serie Fibonacci in c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world, Fibonacci!\n");
    int n, first=0, second=1,next, c;
    printf("Introduceti numarul de numere Fibonacci: ");
    scanf("%d", &n);

    printf("Numerele Fibonacci sunt: %d \n",n);
    for (c=0; c<n; c++){
        if(c<=1)
            next = c;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d\n", next);
    }

    return 0;
}
