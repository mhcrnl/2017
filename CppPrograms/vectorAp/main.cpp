#include <iostream>
#include <vector>
using namespace std;
#include "persoana.h"
int main()
{
    cout << "Hello world!" << endl;

    vector<int> first;
    vector<int>::iterator it;
    first.push_back(23);
    first.push_back(256);
    first.push_back(908);

    for(it=first.begin(); it<first.end(); it++){
        cout<<' '<<*it;
    }

    vector<Persoana> persoane;
    vector<Persoana>::iterator itp;
    Persoana pers("Vasile");

    persoane.push_back(pers);

    for(itp=persoane.begin(); itp<persoane.end(); itp++){
        cout<<' '<<*itp;
    }

    return 0;
}
