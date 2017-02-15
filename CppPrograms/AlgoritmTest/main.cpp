#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<int>::const_iterator iter;
    cout<<"Crearea unui vector de elemente de tip int."<<endl;
    vector<int> scoruri;
    scoruri.push_back(45);
    scoruri.push_back(145);
    scoruri.push_back(450);
    scoruri.push_back(40);
    cout<<"parcurgerea vectorului:\n";
    for(iter=scoruri.begin(); iter != scoruri.end(); ++iter){
        cout<<*iter<<endl;
    }
    cout<<"Cautarea unui scor.";
    int scor;
    cout<<"Introduceti scorul de cautat: ";
    cin>>scor;
    iter=find(scoruri.begin(), scoruri.end(), scor);
    if(iter!=scoruri.end()){
        cout<<"Scorul a fost gasit"<<endl;
    } else {
        cout<<"Scorul nu a fost gasit"<<endl;
    }
    cout<<"Randomizarea scorurilor:";
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(scoruri.begin(), scoruri.end());
    for(iter=scoruri.begin(); iter != scoruri.end(); ++iter){
        cout<<*iter<<endl;
    }
    cout<<"Sortarea vectorului scoruri:";
    sort(scoruri.begin(), scoruri.end());
    for(iter=scoruri.begin(); iter != scoruri.end(); ++iter){
        cout<<*iter<<endl;
    }
    return 0;
}
