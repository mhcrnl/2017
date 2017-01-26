#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include "contact.h"

class Agenda{
    static int index;
    Contact contacte[100];
public:
    void adauga();
    void afiseaza(void);
};

#endif // AGENDA_H_INCLUDED
