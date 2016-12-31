#include <iostream>

using namespace std;

struct carte{
    char titlu[64];
    char autor[64];
    float pret;
};

carte biblioteca[3] =
{
    {"Bancila Vasile", "totul despre c++", 45.67},
    {"Bancila si Vasile", "totul despre noi", 45.45},
    {"Bancila Vasile Andrei", "totul despre c++ si c", 56.67}
};

carte& daCarte(int i){
    if((i>=0) && (i<3))
        return biblioteca[i];
    else
        return biblioteca[0];
}

int main()
{
    cout << "Hello world!" << endl;

    cout<<"Obtinerea cartii se face aici: "<<endl;
    carte& oCarte = daCarte(2);
    cout<<oCarte.titlu<<" "<<oCarte.autor<<" "<<oCarte.pret<<endl;
    return 0;
}
