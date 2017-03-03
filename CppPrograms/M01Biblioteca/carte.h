#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/**
    Clasa Carte utilizata pentru pastrerea unei carti
*/

class Carte{
    static int _nrCrt;//Contor pentru numarul de instante
    string _titlu;
    string _autor;
    string _editura;
    int _an;
    int _nrPagini;
public:
    //Constructorul clasei
    Carte(string titlu, string autor, string editura, int an, int nrPagini);
    //Destructorul clase
    ~Carte() {--_nrCrt;}
    //Metoda statica a clasei care acceseaza valoarea atributului _nrCrt;
    static int getNrCrt();
    //Supraincarcarea operator<< de afisare ca functie membra
    friend ostream& operator<<(ostream& os, const Carte& carte);
    void setTitlu(const string& titlu);
    string getTitlu() const;
};

#endif // CARTE_H_INCLUDED
