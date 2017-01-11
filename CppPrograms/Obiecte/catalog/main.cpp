#include <iostream>
//@file: main.cpp
#include "catalog.h"
#include "profesor.h"
#include "elev.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Catalog unCatalog;
    //un obiect din clasa Elev
    Elev unElev("MKihai Cornel");
    //un obiect din clasa Profesor
    Profesor unProfesor;
    //un eklev isi poate vedea nota
    unElev.VizualizareNota(unCatalog);

    unElev.MarireNota(unProfesor, unCatalog);
    return 0;
}
