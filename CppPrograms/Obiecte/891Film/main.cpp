#include <iostream>
#include <string.h>
using namespace std;
/**
    Classa film definirea acesteia
*/
class Film{
public:
    char numeFilm[65];
    char actorPrincipal[65];
    char actorSecundar[65];

    void initializare(char *film, char *actorPrincipal, char *actorSecundar);
    void arataFilm(void);

    void arataCarte(void){
        arataFilm();
        arataEditura();
    }
    void atribuieEditura(char *nume){ strcpy(editura, nume);}
    char editura[45];
    void arataEditura(void){ cout<<editura<<endl; }

};
/**
    Implementarea functiilor din clasa film
*/
void Film::arataFilm(void){
    cout<<numeFilm<<actorPrincipal<<actorSecundar<<endl;
}

void Film::initializare(char *film, char *rolPrincipal, char *rolSecundar){
    strcpy(numeFilm, film);
    strcpy(actorPrincipal, rolPrincipal);
    strcpy(actorSecundar, rolSecundar);
}
int main()
{
    cout << "Hello world!" << endl;
    Film epocaDeGheata;
    epocaDeGheata.initializare("Epoca de gheata", "Ray Romano", "john leguizamo");
    epocaDeGheata.arataFilm();
    epocaDeGheata.atribuieEditura("Nemira");
    epocaDeGheata.arataEditura();
    return 0;
}
