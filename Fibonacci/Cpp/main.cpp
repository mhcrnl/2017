#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world, Fibonacci!" << endl;
    int n, c, first=0, second=1, next;

    cout << "Introduceti numarul de numere Fibonacci de generat:"<<endl;
    cin>>n;

    cout<<"Numerele Fibonacci sunt: "<<n<<endl;
    for(c=0; c<n; c++){
        if(c<=1)
            next = c;
        else {
            next = first + second;
            first = second;
            second = next;
        }
    cout<<next<<endl;
    }
    return 0;
}
