#include <iostream>

using namespace std;

struct CARTE{
    char titlu[256];
    char autor[256];
    int pret;

    void arataCarte(int numarIsbn){
        cout<<numarIsbn<<titlu<<autor<<pret<<endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;

    CARTE car1 ={"Totul despre c++", "Mihai Cornel", 23};
    car1.arataCarte(1234567);

    CARTE car2={"JavaScript", "Alex Radu", 29};
    car2.arataCarte(987654);
    return 0;
}
