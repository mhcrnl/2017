#include <iostream>

using namespace std;

int suma(int matrice[], int nrElemente){
    int rezultat;
    for(int i=0; i< nrElemente ;i++){
        rezultat+=matrice[i];
    }
    return (rezultat);
}

float suma(float *matrice, int nrElemente){
    float rezultat;
    for(int i=0; i< nrElemente ;i++){
        rezultat+=matrice[i];
    }
    return (rezultat);
}

int main()
{
    cout << "Hello world!" << endl;

    int a[5]={11,2,3,4,5};
    cout<<"Suma valorilor int: "<<suma(a,5)<<endl;

    float b[5]={1.11,2.22,3.33,4.44,5.55};
    cout<<"Suma valorilor float: "<<suma(b,5)<<endl;

    return 0;
}
