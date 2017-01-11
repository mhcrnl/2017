//@file: profesor.cpp
#include "profesor.h"
#include "elev.h"
#include "catalog.h"
void Profesor::ModificareNota(const Elev &elev, Catalog &catalog) const{
    int nota=StabilireNota(elev);
    catalog.ModificareNota(elev, nota);
}
int Profesor::StabilireNota(const Elev &elev) const{
    return 10;
}
