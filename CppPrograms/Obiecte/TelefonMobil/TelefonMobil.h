/**
    Nume fisier: TelefonMobil.h
    Aceste doua directive preprocesor previn includerea
    de mai multe ori a fisierului header
*/
#ifndef TELEFONMOBIL_H_INCLUDED
#define TELEFONMOBIL_H_INCLUDED
//Declararea clasei TelefonMobil
class TelefonMobil{
private:
    int _codPin;
public:
    /**
        Constructorul clasei TelefonMobil, fara parametri.
    */
    TelefonMobil();
    /**
        Metoda de verificare a Pin-ului.
        @param pin - pinul telefonului
        @return bool - Daca pinul corespunde
    */
    bool VerificarePin(int pin);
    /**
        Metoda de modificare pin.
        @param pinNou - Introducerea noului pin.
    */
    void ModificarePin(int pinNou);
    void AcceptareApel(char* numarApelant);
    void EfectuareApel(char* numarApelat);
};


#endif // TELEFONMOBIL_H_INCLUDED
