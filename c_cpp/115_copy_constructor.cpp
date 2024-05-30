#include <iostream>
using namespace std;
/*
kopyalaa kurucusu default sekilde programda vardir eger biz
pointer adresinde bir degiskenimiz varsa bu degisken yeni bir
adresi isaret etsinn istiyorsak kopyalama kurucusunu yazmamiz gerekir
yane kopyalama kurucumuzu pointer ile  islem yaparken  kullanilmali
diger durumlarda program zaten default olarak vermekte
*/

class kordinat{
private:
    int x;
    const int y ;
public:
    kordinat(int ,int);
    kordinat(const kordinat&);//kopyalama kurucusu aldigi nesne sabit nesne olmalidir
    void getkordinat();

};

void kordinat::getkordinat(){
cout <<"x : "<<x<<endl;
cout<<"y : "<<y<<endl;

}
kordinat::kordinat(const kordinat& nesne):y(nesne.y){
    x=nesne.x;
}
kordinat::kordinat(int x, int y):y(y){ //kurucu fonksiyondan once yazýildigi icin haa vermez
//this kulanilmasina gerek yok program hangi degiskenden bahsettigimizi (y(y)) anliyor.
this->x = x;
//this-> y=y ; burda kurucu fonksiyon calistigi icin kulanilirsa hata verecektir
}

int main()
{
    kordinat kordinat1(10,10);
    kordinat1.getkordinat();
    cout<<"-----------------------"<<endl;
    kordinat kordinat2(kordinat1);
    kordinat kordinat3 = kordinat1; //kordinat2 ile ayni sey farkli bir gosterimle yapilmistir.
    kordinat2.getkordinat();
    cout<<"-----------------------"<<endl;
    kordinat3.getkordinat();
    return 0;
}
