/**
    array multidimensional
*/
#include <string>
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    const int SIR = 3;
    const int COLOANE = 3;
    char tabla[SIR][COLOANE]={ {'0', 'X', '0'},
                               {' ','X','X'},
                                {'X','0','0'} };
    cout<<"Tabla de joc tic tac toe:\n";
    for(int i=0; i<SIR;++i){
        for(int j=0; j<COLOANE; ++j){
            cout<<tabla[i][j];
        }
        cout<<endl;
    }
    string meniu[4]={"1.Adauga", "2.Sterge", "3.Salveaza", "4.Afiseaza"};
    for(int i=0; i<4; ++i){
        cout<<meniu[i]<<endl;
    }
    return 0;
}
