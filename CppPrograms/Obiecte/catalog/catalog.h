//@file: catalog.h
#ifndef CATALOG_H_INCLUDED
#define CATALOG_H_INCLUDED
//Declara ca simbolul elev este numele unei clase.
class Elev;
class Catalog{
/**
    Metodele din clasa profesor pot accesa membrii private ai clasei catalog
*/
    friend class Profesor;
public:
    void VizualizareNota(const Elev &elev) const;
private:
    void ModificareNota(const Elev &elev, int nota);
};

#endif // CATALOG_H_INCLUDED
