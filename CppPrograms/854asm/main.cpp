#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world! Instructiuni in cod de asamblare cu asm (keyword)" << endl;

    asm("movq $60, %rax\n\t" // the exit syscall number on Linux
         //"movq $2,  %rdi\n\t" // this program returns 2
         "syscall");

    cout<<"Terminat!"<<endl;
    return 0;
}
