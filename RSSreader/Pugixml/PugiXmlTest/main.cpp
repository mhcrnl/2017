#include <iostream>
#include "../pugixml-1.8/src/pugixml.hpp"
using namespace std;
using namespace pugi;

class ReadXml{
    string file;
public:
    ReadXml(string file){
        xml_document doc;
        //xml_parse_result res = doc.load_file(file);

    }
};
int main()
{
    cout << "Hello world!" << endl;
    xml_document doc;
    xml_document doc1;

    const char* source = "http://www.evz.ro/rss.xml";

    xml_parse_result res = doc1.load_string(source);
    cout<<"RESULT: "<<res.description()<<"TITLE: "<<doc.child("channel").attribute("title").value()<<endl;

    xml_parse_result result = doc.load_file("../PugiXmlTest/evz.xml");
    cout<<"Rezultat: "<<result.description()<<" ," <<doc.child("channel").attribute("title").value();
    cout<<doc.first_child().value()<<doc.child_value("title");
    cout<<doc.attribute("title");

    return 0;


}

