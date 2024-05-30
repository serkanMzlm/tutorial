//kalitim bizim ust sinifimizdaki ozellikleri kulanmamizi saglar

#include <iostream>
using namespace std;

class insan{
protected: //sadece kaltim olarak baglandigimiz siniflara acik kisim
    string ad;
    string soyad;
public:
    insan(string,string);
    void getad();
    void getsoyad();
};

insan::insan(string ad,string soyad){
this->ad=ad;
this->soyad=soyad;

}

void insan::getad(){
cout<<"isminiz : "<<ad<<endl;
}

void insan::getsoyad(){
cout<<"soyadiniz : "<<soyad<<endl;
}

class ogrenci :public insan{ //insan kalitimini alan sinif
private:
    string numara;
public:
    ogrenci(string no,string ad_,string soyad_): numara(no),insan(ad_,soyad_){}
    void getnumara();
};

void  ogrenci::getnumara(){
cout<<"No : "<<numara<<endl;
}
int main()
{
    insan kulanici1("ali","koc");
    ogrenci ogrenci1("170228022","melih","yalin");
    cout<<"-----------------------"<<endl<<"kulanici : "<<endl;
    kulanici1.getad();
    kulanici1.getsoyad();
    cout<<"-----------------------"<<endl<<"ogrenci : "<<endl;
    ogrenci1.getad();
    ogrenci1.getsoyad();
    ogrenci1.getnumara();
    return 0;
}
