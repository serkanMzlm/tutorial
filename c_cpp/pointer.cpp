/*

normalde ozellik cagirmak icin "." kullanilirken pointer da bir ozellik erismek icin "->" kullanilir
degeskenin basina "&" getirilirse  o degiskenin adresini gonderir.
eger bir pointer basina "*" koyarsak o adreste olan degeri gosterir

*/
#include <iostream>
using namespace std; // std programa dahil edildi

class kordinat{
private: // diþardan erisime izin verilmez
    int x;
    int y;
public : // disardan erisime izin verilir
    void degerata(int x,int y){
        this->x = x; //this yazilma sebebi degiskenlerin isimleri ayni olugundan karisiklik olmasin diye
        this->y = y;
}
    void ekrana_yaz(){
        cout<<x<<"\n"<<y;
}
};

int main()
{
   kordinat kordinat1; //nesne tanimlamak
   kordinat* kordinat2;
   kordinat* kordinat3;
   kordinat3 = new kordinat(); //bellekte yeni bir sinif için yer ayrildi
   kordinat2 = &kordinat1; //kordinat1 pointer adresini kordinat2 adresine atandi

   kordinat1.degerata(10,15);
   cout<<"\n"<<"kordinat 1"<<endl; //ekrana yazi gösterme
   kordinat1.ekrana_yaz();
   kordinat2->degerata(200,300);//pointer metorlarina ulasabilmek için -> kullanilir
   cout<<"\n"<<"kordinat 1 pointer ile degisti..."<<endl;
   kordinat1.ekrana_yaz();
   kordinat3->degerata(1000,1000);
   cout<<endl<<"kordinat 3 "<<endl;
   kordinat3->ekrana_yaz();//(*kordinat3).ekrana_yaz(); seklinde yazilabilir
   kordinat dizi[10]; //10 tane nesneli bir dizi olusturuldu
   kordinat* pdizi;
   pdizi = new kordinat[10];// bellekte 10 tane adres tutmus olduk

   //iki diziye (array) deger atama arasinda ki fark =>
   for (int i=0;i<10;i++){
    dizi[i].degerata(i,i*2+5);
   }
   for (int a=0;a<10;a++){
    (pdizi+sizeof(dizi)*a)->degerata(a*5,a*4);//sizeof kulanilma nedeni bellekte tek tek deger degil bir class tuttugu bellek
   // adresi kadar gidilmeli ki ikinci nesneye geçilsin

   }

    return 0;
}
