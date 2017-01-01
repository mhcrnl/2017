#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    char sir[256];
    while(cin.getline(sir, sizeof(sir), '\n'))
        cout<<strupr(sir)<<endl;
    return 0;
}
