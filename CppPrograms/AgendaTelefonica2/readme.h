#ifndef README_H_INCLUDED
#define README_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class CreazaReadme{
    string _fila = "README.md";
    string _text = "## Synopsis\n"

"At the top of the file there should be a short introduction and/ or overview that explains **what** the project is. This description should match descriptions added for package managers (Gemspec, package.json, etc.)\n"

"## Code Example\n"

"Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.\n"

"## Motivation\n"

"A short description of the motivation behind the creation and maintenance of the project. This should explain **why** the project exists.\n"

"## Installation\n"

"Provide code examples and explanations of how to get the project.\n"

"## API Reference\n"

"Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README. For medium size to larger projects it is important to at least provide a link to where the API reference docs live.\n"

"## Tests\n"

"Describe and show how to run the tests with code examples.\n"

"## Contributors\n"

"Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.\n"

"## License\n"

"A short snippet describing the license (MIT, Apache, etc.)\n" ;
public:
    void readme();
    inline bool exists(const string& nume){
        ifstream file(nume.c_str());
        if(!file) //Daca fila nu a fost gasita =0; !file=1 true
            return false;//Fila nu a fost gasita
        else //Daca fila a fost gasita atunci nu este 0
            return true;//Fila a fost gasita
    }
};


#endif // README_H_INCLUDED
