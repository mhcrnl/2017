/**
    @Author: Mihai Cornel
    @file: automobil.cpp
    @date: Martie 2017
*/

#include "automobil.h"

Automobil::Automobil(string model, string nrInmatriculare, unsigned int nrKm, double consum){
    _model = model;
    _nrInmatriculare = nrInmatriculare;
    _nrKm = nrKm;
    _consum = consum;
}
