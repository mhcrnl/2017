//@file: elev.h
#ifndef ELEV_H_INCLUDED
#define ELEV_H_INCLUDED
//Declara ca Profesor si Catalog sunt nume de clase.
class Catalog;
class Profesor;
class  Elev{
    //Numele elevului
    const char* _pNume;
public:
    /**
        Constructor. Argumentul este un pointer catre un sir
        de caracter care reprezinta numele elevului.
    */
    Elev(const char* pNume) : _pNume(pNume){}
    /**
        @return numele elevului
    */
    const char* Nume() const {return _pNume;}
    void VizualizareNota(const Catalog &catalog) const;
    void MarireNota(const Profesor &profesor, Catalog &catalog);
    /**
        Un elev nu isi poate modifica nota intr-un catalog, deoarece
        metoda ModificareNotadin clasa catalog este declarata private si
        in consecinta, inaccesibila din clasa elev. In cazul in care eliminam
         comentariile pt metoda urmatoare  obtinem o eroare la compilare
    */
    /**
        void ModificareNota(Catalog &catalog){
            catalog.ModificareNota(*this, 10);
        }
    */
};

#endif // ELEV_H_INCLUDED
