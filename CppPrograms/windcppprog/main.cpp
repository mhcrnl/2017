#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    deque<int> second(4,100);

    for(deque<int>::iterator it=second.begin(); it != second.end(); ++it)
     cout<<' '<<*it;
    return 0;
}
