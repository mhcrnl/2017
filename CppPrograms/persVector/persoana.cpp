
#include "persoana.h"

Persoana::Persoana(string nume){
    _nume = nume;
}

ostream& operator<<(ostream& os, const Persoana& pers){
    os<<pers._nume;
    return os;
}
