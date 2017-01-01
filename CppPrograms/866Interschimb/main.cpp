#include <iostream>

using namespace std;

void interschimb(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void interschimb(int *a, int *b, int *c, int *d){
    int temp=*a;
    *a=*b;
    *b=temp;
    temp=*c;
    *c=*d;
    *d=temp;
}


int main()
{
    cout << "Hello world!" << endl;

    int a=1, b=2, c=3, d=4;
    interschimb(&a, &b);
    cout<<"Interschimb a cu b: "<<a<<b<<endl;

    interschimb(&a, &b, &c,&d);
    cout<<"Interschimb patru: "<<a<<b<<c<<d<<endl;
    return 0;
}
