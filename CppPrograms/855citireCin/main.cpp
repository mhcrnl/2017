#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    char sir[256];
    int i=0;
    while((sir[i]=cin.get())!= '\n')
        i++;
    sir[i]=NULL;
    cout<<"Sirul a fost: "<<sir<<endl;

    /**
        Scrierea unui caracter cu cout.put(caracter)
    */

    char *titlu ="Totul despre c++";
    while(*titlu) cout.put(*titlu++);

    char litera;
    while((litera=cin.get()) !=-1) {
        cout.put(toupper(litera));
        cout.put(litera);
        cerr.put(litera);
    }
    return 0;
}
