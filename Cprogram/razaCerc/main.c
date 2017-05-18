#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double insert_raza(void){
    double raza;
    scanf("%lf", &raza);
    return raza;
}

void afisare_raza(double raza){
    printf("Aria=%.2lf Perimetrul=%.2lf\n", M_PI*raza*raza, 2*M_PI*raza);
}
int main()
{
    printf("Hello world!\n");
    double raza;
    //scanf("%lf", &raza);
    raza = insert_raza();
    //printf("Aria=%.2lf Perimetrul=%.2lf\n", M_PI*raza*raza, 2*M_PI*raza);
    afisare_raza(raza);
    return 0;
}
