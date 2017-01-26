#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include "contact.h"
#include <fstream>
using namespace std;

class Contact;

class Agenda{
    static int index;
    Contact* contacte[100];
public:
    int incarcaContacte(void);
    void adauga(void);
};
#endif // AGENDA_H_INCLUDED
