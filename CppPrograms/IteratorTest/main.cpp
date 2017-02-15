#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<string> zileleSaptamanii;
    zileleSaptamanii.push_back("Luni");
    zileleSaptamanii.push_back("Marti");
    zileleSaptamanii.push_back("Miercuri");
    cout<<"Parcurgerea vectorului cu ciclul for:\n";
    for(unsigned int i=0; i<zileleSaptamanii.size(); ++i){
        cout<<zileleSaptamanii[i]<<endl;
    }
    //Crearea obiectelor iterator
    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;
    cout<<"PArcurgerea Elementelor cu iteratorul:\n";
    for(iter=zileleSaptamanii.begin(); iter != zileleSaptamanii.end();++iter){
        cout<<*iter<<endl;
    }
    cout<<"Inlocuirea elementului Luni cu Joi."<<endl;
    myIterator = zileleSaptamanii.begin();
    *myIterator = "Joi";
    for(iter=zileleSaptamanii.begin(); iter != zileleSaptamanii.end();++iter){
        cout<<*iter<<endl;
    }
    cout<<"Elementul: "<<*myIterator<<" are "<<(*myIterator).size()<<" litere in el.\n";
    cout<<"Elementul: "<<*myIterator<<" are "<<myIterator->size()<<" litere in el.\n";
    cout<<"Inserarea unui element la inceputul vectorului."<<endl;
    zileleSaptamanii.insert(zileleSaptamanii.begin(), "Duminica");
    for(iter=zileleSaptamanii.begin(); iter != zileleSaptamanii.end();++iter){
        cout<<*iter<<endl;
    }
    cout<<"Stergerea unui element din vector:"<<endl;
    zileleSaptamanii.erase(zileleSaptamanii.begin()+2);
    for(iter=zileleSaptamanii.begin(); iter != zileleSaptamanii.end();++iter){
        cout<<*iter<<endl;
    }
    return 0;
}
