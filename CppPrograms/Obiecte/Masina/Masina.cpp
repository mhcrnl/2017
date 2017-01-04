//Nume Fisier: Masina.cpp
#include "Masina.h"

Masina::Masina(string prod, string model, string numar, unsigned int km){
    _producator=prod;
    _model = model;
    _numarInmatriculare = numar;
    _kilometri = km;
}
void Masina::Afisare(){
    cout<<"PRODUCATOR: "<<_producator<<endl;
    cout<<"MODEL: "<<_model<<endl;
    cout<<"NUMAR INMATRICULARE: "<<_numarInmatriculare<<endl;
    cout<<"KILOMETRII: "<<_kilometri<<endl;
    cout<<endl;
}
void Masina::setKilometri(unsigned int km){
    _kilometri = km;
}
int Masina::kmParcursi(int km){
    int rezultat;
    rezultat = km -_kilometri ;
    return rezultat;
}
void Masina::afisareData(){
    time_t t=time(0);
    struct tm *now = localtime(&t);
    cout<<(now->tm_year+1900)<<'-'
        <<(now->tm_mon+1)<<'-'
        <<now->tm_mday
        <<endl;
}
