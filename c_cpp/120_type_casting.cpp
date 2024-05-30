/**
tip donusumleri pointerla bir siniftan
diger siniflara ulasmak istersek  kapladigi
alan nedeni ile bazi ozellikleri  yer olmadi
gi ici tip donusumu yapilir.
------------------------------------------------------
donusumler  up veya down olabilir yane alt siniflara
yada ust sinifa olur yane baglantisi olmayan siniflarla
sonusturulemez hata 58 satir.
*/
#include <iostream>

using namespace std;

class A {
public:
    string ad ;
    A(string isim):ad(isim){}
};

class B:public A{
public:
   string soyad  ;
   B(string ad ,string soyad):A(ad),soyad(soyad){}
};

class C:public A{
public:
    int no ;
    C(string ad,int numara):A(ad),no(numara){}
};


int main()
{
    A a("ali");
    B b("tolga","celik");
    C c("mehmet",1203);
    cout<<"A sinifi..."<<endl
        <<"ad : "<<a.ad<<endl<<endl;
    cout<<"B sinif..."<<endl
        <<"ad : "<<b.ad<<endl
        <<"soyad : "<<b.soyad<<endl<<endl;
    A* pa[3];
    pa[0] = &a;
    pa[1] = &b;
    pa[2] = &c;
    /**
    bu kisimda  A turunden bir pointer adresi
    alindigi icin  b nin soyad kismi icin  yer
    ayrilmadigi icin bu kisma ulasilamayacak
    bu yuzden tip donusumu yapilir.
    */
    cout<<pa[1]->ad<<endl; // bu yuzden sadece ad kismina ulasir
    B* pb = (B*) pa[1]; //burda tip donusumu yapildi
    cout<<pb->soyad; // bu sayede  soyada erisebiliriz
/**
    C* cp = (B*) pa[2]; bu sekilde atama yapilamaz

    C* cp = (c*) pa[1]; burda da hata yapilmistir cunku pa[1] de
    B sinifinin ozellikleri saklanmaktadir pointer adresi degisiklik
    yaptigimiz icin kontrol sirasindar hataya raslamamiza  fakat cikti
    sirasinda eger farkli boyutlarda bellek adreslerine sahip ozellikler
    cagrilirsa hata alicaz
*/
    return 0;
}
