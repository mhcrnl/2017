#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <sstream>
using namespace std;
/**
    Classa Carte stocarea de carti
*/
class CARTE {
    unsigned int nrCrt;
    string titlu;
    string autor;
    string editura;
    double pret;

public:
    CARTE(){}
    CARTE(unsigned int nrCrt, string titlu, string autor, string editura, double pret);
    /**
        Destructorul
    */
    ~CARTE(){ cout<<"Destructorul a fost apelat."<<endl;}
    void afisare(void);
    void creazaCarte();
    CARTE creazaObiect();
    /**
        Functii get set
    */
    void setNrCrt(unsigned int nr);
    unsigned int getNrCrt(void);
};
 void CARTE::creazaCarte(){
    cout<<"INTRODUCETI NUMARUL CURENT: ";
    cin>>nrCrt;
    cout<<"INTRODUCETI TITLUL CARTII: ";
    getchar();//consuma linia precedenta
    getline(cin, titlu, '\n');
    cout<<"INTRODUCETI AUTORUL: ";
    getline(cin, autor, '\n');
    cout<<"EDITURA: ";
    getline(cin, editura, '\n');
    cout<<"PRETUL: ";
    cin>>pret;
 }
 CARTE CARTE::creazaObiect(){
    CARTE obiect;
    cout<<"INTRODUCETI NUMARUL CURENT: ";
    cin>>nrCrt;
    cout<<"INTRODUCETI TITLUL CARTII: ";
    getchar();//consuma linia precedenta
    getline(cin, titlu, '\n');
    cout<<"INTRODUCETI AUTORUL: ";
    getline(cin, autor, '\n');
    cout<<"EDITURA: ";
    getline(cin, editura, '\n');
    cout<<"PRETUL: ";
    cin>>pret;
    return obiect;
 }
/**
    Functii get set
*/
void CARTE::setNrCrt(unsigned int nr){
    if(nr > 0){
        nrCrt=nr;
    } else {
        cout<<"INTRODUCETI UN NUMAR MAI MARE CA 0."<<endl;
    }
}
unsigned int CARTE::getNrCrt(void){
    return nrCrt;
}
/**
    Functia speciala constructor
*/
CARTE::CARTE(unsigned int nr, string tit, string aut, string edit, double p){
    nrCrt=nr;
    titlu=tit;
    autor=aut;
    editura=edit;
    pret=p;
}
/**
    Functia de afisare a datelor
*/
void CARTE::afisare(void){
    cout<<"TITLUL: "<<titlu<<"  AUTOR(I): "<<autor<<endl;
    cout<<"NUMARUL CURENT: "<<nrCrt<<" EDITURA: "<<editura<<" PRET: "<<pret<<endl;
}
int main()
{
    cout << "Hello world!" << endl;

    CARTE carte(1, "Totul despre C si C++", "Dr. Kris Jamsa & Lars Klander", "Teora", 76.65);
    carte.setNrCrt(101);
    cout<<"NUMARUL CURENT: "<<carte.getNrCrt()<<endl;
    carte.afisare();

    CARTE carte1;
    carte1.creazaCarte();
    carte1.afisare();

    CARTE carte2;
    carte2.creazaObiect();
    carte2.afisare();

    return 0;
}
