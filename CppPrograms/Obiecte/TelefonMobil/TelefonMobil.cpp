//Nume fisier: TelefonMobil.cpp
#include "TelefonMobil.h"
#include <iostream>
using namespace std;

TelefonMobil::TelefonMobil():_codPin(0){}
//Definitia metodei VerificarePin
bool TelefonMobil::VerificarePin(int pin){

    return (_codPin == pin);
}
void TelefonMobil::ModificarePin(int pinNou){_codPin = pinNou; }
void TelefonMobil::AcceptareApel(char* numarApelant){
    cout<<"Apel de la: "<<numarApelant<<endl;
}
void TelefonMobil::EfectuareApel(char* numarApelat){
    cout<<"Apel catre: "<<numarApelat<<endl;
}
