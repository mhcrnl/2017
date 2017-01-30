#include <iostream>
#include <vector>
using namespace std;

class Nume{
public:
    virtual void afiseazaNume()=0;
};
class Mihai:public Nume{
public:
    void afiseazaNume(){
        cout<<"Mihai"<<endl;
    }
};
class Irina:public Nume{
    void afiseazaNume(){
        cout<<"Irina"<<endl;
    }
};
class Aspazia:public Nume{
    void afiseazaNume(){
        cout<<"Aspazia"<<endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    vector<Nume*> persoane;
    while(true){
        int alegere;
        cout<<"1.Mihai; 2.Irina; 3.Aspazia; 0.Nimic;";
        cin>>alegere;
        if(alegere==0) break;
        if(alegere==1){
            persoane.push_back(new Mihai);
        }
        if(alegere==2){
            persoane.push_back(new Irina);
        }
        if(alegere == 3){
            persoane.push_back(new Aspazia);
        }
    }
    for(int i=0; i<persoane.size();i++){
        persoane[i]->afiseazaNume();
    }
    for(int i=0; i<persoane.size();i++){
        delete persoane[i];
    }
    return 0;
}
