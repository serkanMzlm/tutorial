#include <iostream>

using namespace std;

class tarih {
private:
    int gun, ay, yil;

public:
    void gettarih();
    void settarih(int,int,int );
    friend ostream& operator  <<  ( ostream& , tarih&); // get fonksiyonu yerine direk ekranda gostermek için ostream arkadaþ yaptik
};

 void tarih:: gettarih(){
    cout<<gun<<"."<<ay<<"."<<yil<<endl;
 }

 void tarih::settarih(int g,int a,int y){
    gun = g;
    ay = a;
    yil = y;
 }

 ostream& operator << (ostream& o ,tarih&tarih1) {
        o << tarih1.gun <<"."<<tarih1.ay<<"."<<tarih1.yil<<endl;
        return o;
 }

int main(){
    tarih tarih1;
    tarih1.settarih(10,12,2021);
    //36-37 satirlarin ciktilari ayni olur eger ostream ile friend yapmasaydik  37 satirda hata alirdik
    tarih1.gettarih();
    cout <<tarih1;
    return 0;
}
