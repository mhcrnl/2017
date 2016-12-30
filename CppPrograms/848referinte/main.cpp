#include <iostream>

using namespace std;

void modificare_val(int& val_referinta){
    val_referinta=1500;
}
int main()
{
    cout << "Hello world!" << endl;
    int valoare=10;
    int& alias = valoare;
    cout<<"Valoarea inaintea functiei: "<<valoare<<endl;
    modificare_val(alias);
    cout<<"Valoarea dupa functie: "<<valoare<<endl;
    modificare_val(valoare);
    cout<<"Valoarea dupa functie: "<<valoare<<endl;

    return 0;
}
