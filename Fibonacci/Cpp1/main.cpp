/**
    Fibonacci
    main.cpp
    07/06/2017
    Mihai Cornel
*/
#include <iostream>
#include <sstream>
using namespace std;
void PrintFibonacciRecursive(int first, int second, int& lengthOfSequence){
    if(lengthOfSequence == 0) return;
    int next = first + second;
    cout <<next<<endl;
    PrintFibonacciRecursive(second, next, --lengthOfSequence);
}
void PrintFibonacci(int lengthOfSequence){
    int first = 0;
    cout << first<< endl;
    int second = 1;
    cout<< second<<endl;
    lengthOfSequence -=2;
    PrintFibonacciRecursive(first, second, lengthOfSequence);
}
string GetLine() {
    string input;
    getline(cin, input);
    return input;
}
int GetInteger(){
    while(true) {
        cout<<"Introduceti un numar: ";
        stringstream converter;
        char extra;
        int result;

        converter << GetLine();
        converter >> result;

        if (converter.fail()){
            cout << "Nu este un numar intreg!"<<endl;
        } else if (converter >> extra){
            cout << "Caracter neasteptat: "<< extra <<endl;
        } else {
            return result;
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    int lengthOfSequence = GetInteger();
    PrintFibonacci(lengthOfSequence);
    return 0;
}
