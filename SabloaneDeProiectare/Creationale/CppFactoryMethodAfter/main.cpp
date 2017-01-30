#include <iostream>
#include <vector>
using namespace std;
class Nume{
public:
    //FactoryMethod
    static Nume* creazaNume(int choise);
    virtual void afiseazaNume() = 0;
    virtual ~Nume()=default;
};
int main()
{
    cout << "Hello world!" << endl;
    vector<Nume*> persoane;
    int alegere;
    while(true){
        cout<<"1.Mihai; 2.Irina; 3.Aspazia; 0.Nimic:";
        cin>>alegere;
        if(alegere==0) break;
        persoane.push_back(Nume::creazaNume(alegere));
    }
    for(unsigned int i=0; i<persoane.size();i++){
        persoane[i]->afiseazaNume();
    }
    for (unsigned int i=0; i<persoane.size();i++){
        delete persoane[i];
    }
    return 0;
}
class Mihai:public Nume{
public:
    void afiseazaNume(){
        cout<<"MIhai"<<endl;
    }
};
class Irina:public Nume{
public:
    void afiseazaNume(){
        cout<<"Irina"<<endl;
    }
};
class Aspazia:public Nume{
public:
    void afiseazaNume(){
        cout<<"Aspazia"<<endl;
    }
};
Nume* Nume::creazaNume(int alegere){
    if(alegere ==1 )
        return new Mihai;
    else if(alegere==2)
        return new Irina;
    else
        return new Aspazia;
}
