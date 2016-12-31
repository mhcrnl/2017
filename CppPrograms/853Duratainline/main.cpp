#include <iostream>
#include <ctime>

using namespace std;

inline void interschimb_inline(int *a, int *b, int *c, int *d){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    *c =*d;
    *d=temp;
}

void apel_interschimb(int *a, int *b, int *c, int *d){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    *c =*d;
    *d=temp;
}

int main()
{
    cout << "Hello world!" << endl;

    clock_t start, stop;
    int a=1, b=2, c=3, d=4;

    start=clock();
    for(int i=0; i< 3000000 ;i++){
        interschimb_inline(&a, &b, &c, &d);
    }
    stop=clock();
    cout<<"Apel interschimb_inline: "<<stop-start<<endl;

    start=clock();
    for(int i=0; i< 3000000 ;i++){
        apel_interschimb(&a, &b, &c, &d);
    }
    stop=clock();
    cout<<"Apel interschimb: "<<stop-start<<endl;

    return 0;
}
