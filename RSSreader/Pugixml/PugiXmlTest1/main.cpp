#include <iostream>
#include "pugixml.hpp"
using namespace std;
using namespace pugi;
class ReadXml{
    const char* path;
public:
    ReadXml(const char* path){
        xml_document doc;
        xml_parse_result result = doc.load_file(path);
        cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << endl;
        cout<<doc.child("node").attribute("attr1").value();
    }
};
int main()
{
    cout << "Hello world!" << endl;

    ReadXml("tree.xml");






    return 0;
}
