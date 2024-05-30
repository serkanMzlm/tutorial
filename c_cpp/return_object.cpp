#include <iostream>

using namespace std;

class  sayi{
private:
    int x;
    int y;
public:
    sayi(int,int);
    void getsayi()const;
    sayi topla(sayi&);
    sayi cikar(sayi&);
};

sayi::sayi(int x ,int y){
this->x = x;
this->y = y;
}

void sayi::getsayi()const{
cout<<"-----------------------------"<<endl;
cout<<"x : "<<x<<endl;
cout<<"y : "<<y<<endl;
cout<<"-----------------------------"<<endl;
}

sayi sayi::topla(sayi& nesne){
int x = this->x + nesne.x;
int y = this->y + nesne.y;
return sayi(x,y);

}

sayi sayi::cikar(sayi& nesne){
int x = this->x - nesne.x;
int y = this->y - nesne.y;
return sayi(x,y);

}

int main()
{
    sayi sayi1(10,12);
    sayi sayi2(20,24);
    sayi2.getsayi();
    sayi1.getsayi();
    sayi sayi3 = sayi1.topla(sayi2);
    (sayi1.topla(sayi2)).getsayi(); //sayiyi bir nesneye aktarmadan gostermek istersek tek seferligine
    //bu sekilde gosterilebilir.
    sayi3.getsayi();
    sayi sayi4 = sayi1.cikar(sayi2);
    sayi4.getsayi();

    return 0;
}
