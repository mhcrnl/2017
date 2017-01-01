#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char sir[256];
    cout<<"Introduceti numele/prenumele urmat de enter: ";
    cin.getline(sir, sizeof(sir), '\n');
    cout<<sir<<endl;

    return 0;
}
