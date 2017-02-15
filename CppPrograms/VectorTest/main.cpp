/**
Utilizarea clasei vector in programe cpp si functiile
push_back(), empty() etc..
*/
#include <iostream>
#include <string>
#include <vector> // includerea clasei vector
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    //Construirea unui obiect de tip Vector care contine elemente string
    vector<string> lunileAnului;
    //Adaugarea de elemente la sfarsitul vectoruului.
    lunileAnului.push_back("Ianuarie");
    lunileAnului.push_back("Februarie");
    lunileAnului.push_back("Martie");
    //Numarul de elemente din vector
    cout<<"Numarul de elemente este: "<<lunileAnului.size()<<endl;
    //Afisarea numarului de litere din elementul 0
    cout<<"Numarul de litere din elementul 0: "<<lunileAnului[0].size()<<endl;
    //Parcurgerea vectorului si afisarea elementelor cu for
    cout<<"Elementele din vector sunt:\n";
    //unsigned deoarece size() returneaza unsigned int
    for(unsigned int i=0; i<lunileAnului.size(); ++i){
        cout<<lunileAnului[i]<<endl;
    }
    //Introducerea unui nou element
    lunileAnului.push_back("Aprilie");
    cout<<"Elementele din vector sunt:\n";
    //unsigned deoarece size() returneaza unsigned int
    for(unsigned int i=0; i<lunileAnului.size(); ++i){
        cout<<lunileAnului[i]<<endl;
    }
    //Stergerea unui element din vector
    lunileAnului.pop_back();
    cout<<"Elementele din vector sunt:\n";
    //unsigned deoarece size() returneaza unsigned int
    for(unsigned int i=0; i<lunileAnului.size(); ++i){
        cout<<lunileAnului[i]<<endl;
    }
    cout<<"Stergerea Elementelor din vector: "<<endl;
    lunileAnului.clear();
    if(lunileAnului.empty()){
        cout<<"Nu exista elemente in vector.\n";
    } else {
        cout<<"Aveti cel putin un element in vector.\n";
    }
    return 0;
}
