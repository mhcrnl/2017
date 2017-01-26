#include <iostream>
#include "contact.h"
using namespace std;
#include "agenda.h"
#include "controler.h"
int main()
{
    cout << "Hello world!" << endl;
    Contact con;
    con.setNume("Vasile");
    cout<<"Nume: "<<con.getNume()<<endl;
    con.setPrenume("Alexandru");
    cout<<"Prenume: "<<con.getPrenume()<<endl;
    con.setNrTel("0722270796");
    cout<<"Numar telefon: "<<con.getNrTel()<<endl;

    Agenda age;
    age.adauga();
    meniu();

    Controler cont;
    cont.startAplicatie();
    return 0;
}
