/**
    @file: readme.cpp
*/
#include "readme.h"

void CreazaReadme::readme(){

    if(exists(_fila.c_str())){
        cout<<"Fila "<<_fila<<" exista deja!"<<endl;
        return;
    }

    ofstream scrie(_fila.c_str());
    if(scrie.is_open()){
        scrie<<_text;
        scrie.close();
    } else {
        cout<<"Fila "<<_fila<<" nu a fost scrisa."<<endl;
    }
}
