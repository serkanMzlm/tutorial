/**
Diomond  problemi coklu kalitimda
ilk kaltim alinan yerin ozelligi bir kac
kez cagrilacakti  bunu engellemek icin
--------------------------------------
virtual sayesinde alta bulunan ornekte
kullanilarak  kalitim alinan yer sadece
bir kez kullanilmis olur.
---------------------------------------
virtual  kullanilmaz ise  D class cagril-
diginda  A sinifi iki kez cagrilir.
---------------------------------------
virtual  kulanildigi icin  her hangi ozellige 
erismek icin scope belirtmek  gerekmez
*/

#include <iostream>
using namespace std;

class A {
public:
    A() {cout<<"A  sinifi ..."<<endl;}
};

class B:virtual public A{
public:
    B() {cout<<"B  sinifi ..."<<endl;}
};

class C: virtual public A{
public:
    C() {cout<<"C  sinifi ..."<<endl;}
};

class D final :public B,public C{  //final kelimesi bu sınıfatan başka sınıfa kalıtım verilmesini engeler.
public:
     D() {cout<<"D  sinifi ..."<<endl;}
};

int main()
{
    A a;
    cout<<endl;
    B b;
    cout<<endl;
    C c;
    cout<<endl;
    D d;
    return 0;
}
