#include <iostream>
#include "persoana.h"
using namespace std;
#include <vector>


int main()
{
    cout << "Hello world!" << endl;
    vector<Persoana> persoane;
    //Persoana pers("Vasile");
    //cout<<pers<<endl;
    string nume;
    for(int i =0; i<5; ++i){
        cout<<"Introduceti numele Persoanei: ";
        cin>>nume;
        Persoana persoana(nume);
        persoane.push_back(persoana);
        nume =" ";
    }
    //persoane.push_back(persoana);
    cout<<persoane.capacity();

    cout<<"Accesarea Vectorului: "<<endl;
    for(vector<Persoana>::iterator it =persoane.begin(); it != persoane.end(); ++it ){
        cout<<*it;

    }
    return 0;
}
