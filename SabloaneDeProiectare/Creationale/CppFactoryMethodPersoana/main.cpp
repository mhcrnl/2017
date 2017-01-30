#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
using namespace std;
class Persoana{
public:
    Persoana() = default;
    ~Persoana() = default;
    virtual string getNume()=0;
    virtual string getPrenume()=0;
    virtual void afiseaza()=0;
    static Persoana* creazaPersoana(int alegere);
};
class Contact:public Persoana{
    string _nume;
    string _prenume;
    string _nrTel;
public:
    Contact(){
        _nume = setNume();
        _prenume = setPrenume();
        _nrTel = setNrTel();
    }
    Contact(string nume, string prenume, string nrTel){
        _nume = nume;
        _prenume = prenume;
        _nrTel= nrTel;
    }
    ~Contact(){};
    string getNume() override{
        return _nume;
    }
    string setNume(void){
        cout<<"Introduceti numele contactului: ";
        cin>>_nume;
        return _nume;
    }
    string getPrenume() override{
        return _prenume;
    }
    string setPrenume(void){
        cout<<"Introduceti prenumele contactului: ";
        cin>>_prenume;
        return _prenume;
    }
    string getNrTel(){
        return _nrTel;
    }
    string setNrTel(void){
        cout<<"Introduceti numarul de telefon: ";
        cin>>_nrTel;
        return _nrTel;
    }
    void afiseaza() override{
        cout<<_nume<<" "<<_prenume<<" "<<_nrTel<<endl;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    vector<Persoana*> persoane;
    int alegere;
    while(true){
        cout<<"1. Adauga Contact; 0. Inchide"<<endl;
        cin>>alegere;
        if(alegere==0) break;
        persoane.push_back(Persoana::creazaPersoana(alegere));
    }
    for(unsigned int i=0; i<persoane.size(); i++){
        persoane[i]->afiseaza();
    }
    for(unsigned i =0; i<persoane.size();i++){
        delete persoane[i];
    }
    return 0;
}
Persoana* Persoana::creazaPersoana(int alegere){
    if(alegere==1) return new Contact;
    else return NULL;
}
