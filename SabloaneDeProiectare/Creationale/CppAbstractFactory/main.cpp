#include <iostream>
#define LINUX
using namespace std;
class Widget {
public:
    virtual void draw()=0;
};
class LinuxButton:public Widget{
public:
    void draw(){cout<<"LinuxButton\n";}
};
class LinuxMenu:public Widget{
public:
    void draw(){cout<<"LinuxMenu\n";}
};
class WindowsButton:public Widget{
public:
    void draw(){cout<<"WindoewsButton\n";}
};
class WindowsMenu: public Widget{
public:
    void draw(){cout<<"WindowsMenu\n";}
};
class Client{
public:
    void draw(){
#ifdef LINUX
    Widget *w=new LinuxButton;
#else /**Windows*/
    Widget *w = new WindowsButton();
#endif // LINUX
    w->draw();
    display_window_one();
    //display_window_two();
    }
    void display_window_one(){
#ifdef LINUX
    Widget *w[]={
        new LinuxButton,
        new LinuxMenu
        };
#else //Windows
    Widget *w[] ={
        new WindowsButton,
        new WindowsMenu
    };
#endif // LINUX
    w[0]->draw();
    w[1]->draw();
    }
    void dysplay_window_two(){
#ifdef LINUX
    Widget *w[] ={
        new LinuxMenu,
        new LinuxButton
    };
#else //Windows
    Widget *w[]={
        new WindowsMenu,
        new WindowsButton
    };
#endif // LINUX
    w[0]->draw();
    w[1]->draw();
    }
};
int main()
{
    cout << "Hello world!" << endl;
    Client *c = new Client();
    c->draw();
    return 0;
}
