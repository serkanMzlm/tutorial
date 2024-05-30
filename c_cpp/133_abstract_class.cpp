/* soyut sinif  kendisinden olusan
* butun siniflarda olmasini istedigimiz zaman
* bu metodu kullaniriz  bu metodu kulandigmizda o
* siniftan yeni bir nesne olusturamayiz
* polymorphism   biraz daha kati kuralli hali diyebiliriz */
#include <iostream>

using namespace std;

class sekil{
public:
    virtual void nesne()=0; //artik soyut  oldu artik alt siniflarinda
    //bu fonksiyon bulunmak zorunda
};

class daire:public sekil{
public:
    void nesne(){cout<<"daire..."<<endl;}
};

class kare:public sekil{
    void nesne(){cout<<"kare..."<<endl;}
};

int main(){
    sekil* sp[2];
    sp[0] = new daire();
    sp[1] = new kare();
    sp[1]->nesne();
    sp[0]->nesne();
    return 0;
}
