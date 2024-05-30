#include <iostream>
/**
ezme aslinda kalitsa olarak bagli siniflarin isimleri ayni
olan fonksyonlarindan onceligi kendi siniflarina vermeleri
olayidir.
    */
using namespace std;
class sinif1{
public:
    int data[10];
    int deger;
    sinif1():deger(0){}

    void ekle(int d){
    data[deger]= d;
    deger++;
    }

    void goster(){
        cout<<"sinif1 : "<<endl;
    for (int i=0;i<deger;i++){
        cout<<data[i]<<endl;
    }
    }

};
class sinif2: public sinif1 {

public:
    float data[10];
    int deger;
    sinif2():deger(0){}

    void ekle(float d){
    data[deger]= d;
    deger++;
    }

    void goster(){
        cout<<"sinif2 : "<<endl;
        sinif1::goster();// eger diger siniftaki gostere gitmek istiyorsak
    for (int i=0;i<deger;i++){
        cout<<data[i]<<endl;
    }
    }
};
int main()
{
   sinif1 deger1;
   sinif2 deger2;
   deger2.ekle(1.2);
   deger2.ekle(1.3);
   deger2.ekle(1.4);
   deger1.ekle(80);
   deger1.ekle(15);
   deger1.ekle(20);
   deger1.goster();
   cout<<"-----------------------------"<<endl;
   deger2.goster();
    return 0;
}
