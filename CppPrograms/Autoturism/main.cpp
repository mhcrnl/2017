#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Autoturism{
    int _service;
    int _itp;
    int _valore;
};

class Clio{
    int _km;
    double _consum;
    float _pretLitruBenzina;

public:
    int getKm() const{
        return _km;
        cout<< _km<<endl;
    }
    void setKm(int km){
        _km = km;
        cout<<_km<<endl;
    }
    double getConsum() const{
        cout<<_consum<<endl;
        return _consum;

    }
    void setConsum(double consum){
        _consum = consum;
        cout<<_consum<<endl;
    }
    float getPretLitruBenzina() const {
        cout<<_pretLitruBenzina<<endl;
        return _pretLitruBenzina;
    }
    void setPretLitruBenzina(float pretLitruBenzina){
        _pretLitruBenzina=pretLitruBenzina;
        cout<<_pretLitruBenzina<<endl;
    }
    double combustibilConsumat(){
        double combConsumat;
        combConsumat= (_km/100)*_consum;
        cout<<"Combustibil consumat: "<<combConsumat<<" litri."<<endl;
        return combConsumat;
    }
    float costTotalCarburant(){
        float costCarburant;
        costCarburant = combustibilConsumat()*_pretLitruBenzina;
        cout<<"Costul Total Carburant: "<<costCarburant<<" lei."<<endl;
        return costCarburant;
    }
    double costPerKm(){
        double costKm;
        costKm = _km/costTotalCarburant();
        cout<<"Cost per KM: "<<costKm<<" lei."<<endl;
        return costKm;
    }
    void vechime(){
        time_t acum = time(0);
        time_t acum2 = time(0);
        char* local = ctime(&acum);
        tm* local2 = localtime(&acum2);
        cout<<"Data si ora locale: "<< local<<endl;
        cout<<1900+local2->tm_year<<endl;
    }
    int vechime(int anCumparare){
        time_t acum = time(0);
        tm* local = localtime(&acum);
        int anCurent = 1900+local->tm_year;
        int varsta = anCurent - anCumparare;
        cout<<"VECHIME: "<<varsta<<" ani."<<endl;
        return varsta;
    }
    void afisare(){
        cout<<"Kilometri | Consum | Pret carburant |"<<endl;
        cout<<setw(7)<<_km<<setw(10)<<_consum<<setw(10)<<4.89<<endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Clio clio;
    clio.setKm(21345);
    clio.setConsum(7.3);
    clio.setPretLitruBenzina(4.89);
    clio.combustibilConsumat();
    clio.costTotalCarburant();
    clio.costPerKm();
    clio.vechime(2015);
    cout<<clio.vechime(2014)<<endl;
    clio.afisare();
    return 0;
}
