#include <iostream>
#include "contact.h"
#include "agenda1.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Agenda1 agen, agen1;
    agen.adauga("Mihai", "Cornel", "0722270796");
    agen.adauga("Radu", "Vasile", "0987654321");
    agen.afisare();
//    int index =-1;
//    Contact contacte[100];
//    Contact con;
//    if(index == -1){
//        index++;
//    }
//
//    cin>>con;
//    contacte[index].getNume();
//    contacte[index].getPrenume();
//    contacte[index].getNrTel();
//    cout<<con;
//    cout<<con.getNume()<<" "<<con.getPrenume()<<" "<<con.getNrTel()<<endl;
//    con.scrieInFila("contact.txt", con);

    //Agenda agen;
    //agen.incarcaContacte();
    return 0;
}
