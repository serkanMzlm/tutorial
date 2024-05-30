#include<iostream>
using namespace std;

class Foo
{
private:
  int m_foo;

public:
  Foo (int foo) : m_foo (foo) {}

  int GetFoo () { cout<<m_foo<<endl; return m_foo; }
};


class Foo1
{
private:
  int m_foo;

public:
  explicit Foo1 (int foo) : m_foo (foo) {}

  int GetFoo () { cout<<m_foo<<endl; return m_foo; }
};



void my_func (Foo foo)
{
  int i = foo.GetFoo ();
}

void my_func1 (Foo1 foo)
{
  int i = foo.GetFoo ();
}

int main(){
    
    my_func(20);
    /* bu kısım hata veriri explicit arka planda tür dönüşümü yapılamısnı engeler. Üst kısımda bulunan kodun çalışma
    nedeni constructor bir tane int değer aliyor bu kısımda tür dönüşümü yapılıp o int sayı fonksiyon içinde foo yapıcını çalıştırıyor gibi alınıyor
    explicit eklersek mecburen bu olayı bizim yapmamız gerekeçek
    */
    my_func1((Foo1)39);
}
