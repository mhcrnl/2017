#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>

#include "persoana.h"

using namespace std;

#define NUMAR 1
Persoana listaPersoane1[NUMAR];
int nrPersoaneInLista = 0;

void meniu(void);

void control(void);

void adaugareInLista();

void afisare();

#endif // CONTROL_H_INCLUDED
