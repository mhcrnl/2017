#include <iostream>
#include <deque>
#include <cstring>

//#include "std_lib_facilities.h"
using namespace std;

class Persoana{
public:
    string nume;
    string prenume;

    Persoana(string n, string p){
        nume =n;
        prenume=p;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    deque<Persoana> dequePers;
    Persoana persoana("Mihai", "Cornel");
    dequePers.push_front(persoana);

    for (deque<Persoana>::iterator it = dequePers.begin(); it!=dequePers.end(); ++it)
        cout<<it->prenume << ' ' << it->nume;

    return 0;
}
