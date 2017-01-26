#include <iostream>
#include "persoana.h"
#include "contact.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Persoana pers("Mihai");
    Persoana pers1;
    pers1.setNume("Vasile");
    cout<<pers1;
    cout<<pers;
    Contact con();
    //con.getNume();
    return 0;
}
