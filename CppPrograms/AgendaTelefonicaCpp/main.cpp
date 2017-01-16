#include <iostream>

using namespace std;
#include "contact.h"
int main()
{
    cout << "Hello world!" << endl;
    Contact con;
    Contact con1("Mihai", "Cornel", "0722270796");
    con = con1;
    cout<<con<<endl;
    cout<<con.getNume()<<endl;
    con.setNume("Andrei");
    cout<<con.getNume()<<endl;
    con.setNume("Vasile", 5);
    return 0;
}
