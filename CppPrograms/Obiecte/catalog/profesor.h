//@file: profesor.h
#ifndef PROFESOR_H_INCLUDED
#define PROFESOR_H_INCLUDED
//Declara ca Elev si Catalog reprezinta nume de clase.
class Elev;
class Catalog;
class Profesor{
public:
    void ModificareNota(const Elev &elev, Catalog &catalog) const;
private:
    int StabilireNota(const Elev &elev) const;
};
#endif // PROFESOR_H_INCLUDED
