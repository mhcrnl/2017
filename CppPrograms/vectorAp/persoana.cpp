#include "persoana.h"

Persoana::Persoana(string nume){
    _nume = nume;
}

ostream& operator<<(ostream& is, const Persoana& pers){
    is<<pers._nume<<' '<<endl;
    return is;
}
