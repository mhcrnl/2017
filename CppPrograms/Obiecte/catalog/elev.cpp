//@file: elev.cpp
#include "elev.h"
#include "catalog.h"
#include "profesor.h"
void Elev::VizualizareNota(const Catalog &catalog) const{
    catalog.VizualizareNota(*this);
}
void Elev::MarireNota(const Profesor &profesor, Catalog &catalog){
    //elevul poate obtine modificarea unei note numai prin profesor.
    profesor.ModificareNota(*this, catalog);
}
