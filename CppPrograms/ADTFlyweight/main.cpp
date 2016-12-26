/**
    Flyweight design pattern before
*/

#include <iostream>

using namespace std;

class Gazillion{
public:
    Gazillion(){
        m_value_one = s_num/y;
        m_value_two = s_num%y;
        ++s_num;
    }
    void report(){
        cout<<m_value_one<<m_value_two<<' ';
    }
    static int x, y;
private:
    int m_value_one;
    int m_value_two;
    static int s_num;
};

int Gazillion::x=6, Gazillion::y = 10, Gazillion::s_num=0;

int main()
{
    cout << "Hello world!Flyweight Design pattern before." << endl;

    Gazillion matrix[Gazillion::x][Gazillion::y];
    for(int i=0; i<Gazillion::x; ++i){
        for(int j=0; j<Gazillion::y; ++j)
            matrix[i][j].report();
        cout<<"\n";
    }
    return 0;
}
