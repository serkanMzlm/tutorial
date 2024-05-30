/**
eger ayni isimde ozelliklerimiz
veya metotlarimiz varsa bu iki classi
ayni diziye koyarsak  bu metotlar
cagirilirken ezme (override) olacagindan
baskin ozellik surekli bize verilicektir
bunlarin onune gecmek icin polymorphism
kullanilir.
*/
#include <iostream>

using namespace std;

class film{
public:
    virtual void yaz(){
    cout<<"film ..."<<endl;
    }

};

class korku: public film{
public:
    void yaz(){
    cout<<"korku filmi ..."<<endl;
    }
};
/**
film yaz fonksiyonu surekli korku  yaz metodunu
ezeceginden virtual kavrami kullandik
*/
int main()
{
    film f;
    korku k;
    f.yaz();
    k.yaz();

    film* pf[2];
    pf[0] = &f;
    pf[1] = &k;

    pf[0]->yaz();
    pf[1]->yaz();
    return 0;
}
