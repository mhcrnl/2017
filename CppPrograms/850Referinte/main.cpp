#include <iostream>
#include <iomanip>

using namespace std;
void apelPrinValoare(int a, int b, int c){
    a=3; b=2; c=1;
}
void apelPrinReferintaPointer(int *a, int *b, int *c){
    *a=3; *b=2; *c=1;
}
void apelPrinReferinta(int& a, int& b, int& c){
    a=3; b=2; c=1;
}
int main()
{
    cout << "Hello world!" << endl;
    int a=1, b=2, c=3;

    apelPrinValoare(a,b,c);
    cout<<"ApelPrinValoare: "<<a<<b<<c<<endl;
    apelPrinReferintaPointer(&a, &b, &c);
    cout<<"ApelPrinReferintaPointer: "<<a<<b<<c<<endl;
    apelPrinReferinta(a, b, c);
    cout<<"ApelPrinReferinta: "<<a<<b<<c<<endl;
    return 0;
}
