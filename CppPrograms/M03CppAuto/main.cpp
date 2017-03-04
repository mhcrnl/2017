#include <iostream>
#include "automobil.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Automobil clio("Clio", "B64RDD", 21345, 7.3);
    Automobil logan;
    logan.setModel("Logan");
    cout<<logan.getModel()<<endl;
    cout<<clio<< endl;

    cout<<"CARBURANT CONSUMAT: "<<clio.consumCarburant()<<" LITRI."<<endl;
    cout<<"COST TOTAL CARBURANT: "<<clio.costTotalCarburant(4.97)<<" LEI."<<endl;
    return 0;
}
