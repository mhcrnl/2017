#include <iostream>
#include <array>

using namespace std;

class Digi{
public:
    int cost;
    Digi operator<<(Digi dg){
        cout<<dg.cost;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    array<int, 12> myCost={23, 34, 56, 45,32,34,56,56, 56,67,89,90};

    for (auto it=myCost.begin(); it != myCost.end(); ++it)
        cout<<' '<<*it;
    cout<<endl;
    int total;
    for(auto it1=myCost.begin(); it1!=myCost.end();++it1){

        total+=*it1;


    }
    cout<<"TOTAL: "<<total<<endl;
    cout<<"Media lunara: "<<total/myCost.size()<<endl;

    return 0;
}
