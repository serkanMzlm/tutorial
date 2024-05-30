#include <iostream>
/*

static degiskenlerimiz bellekte ayni yeri tutarlar scope cikilsada degerlerini korurlar
auto default olarak degiskenlerimizin basindadir. Bellekte  cagrildikca yeni yer ayirir
degerini scope cikinca siler.

*/
using namespace std;

class sayi{
private:
    int x =0;
    static int y;
public:
    sayi();
    void getsayi();
};

void sayi:: getsayi(){
//bellek adreslerini gostererek  statick  belleklek farkini daha net gorulur.
cout<<"-----------------------------------"<<endl;
cout<<"x : "<<x<<endl;
cout<<"x adresi : "<<&x<<endl;
cout<<"-----------------------------------"<<endl;
cout<<"y : "<<y<<endl;
cout<<"y adresi : "<<&y<<endl;
}

sayi::sayi(){
//ikisininda degeri bir artirilarak arasinda olusan fark belli eder
y++;
x++;
}

int sayi::y=0; //private kisminda oldugu icin bunu bir kez yapabiliriz
//bir baslangic degeri vermek zorundayiz

int main()
{
    //her nesne olusturdugumuzda static degiskenimiz bir artarken digeri
    // surekli bastan olusur bu yuzden degeri  ayni kalir.
    sayi sayi1;
    sayi1.getsayi();
    sayi sayi2;
    sayi2.getsayi();
    sayi sayi3;
    sayi3.getsayi();


    return 0;
}
