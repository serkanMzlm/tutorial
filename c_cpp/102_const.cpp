#include <iostream>

#define INITIATION number(1358), height(1.58)

class MyClass{
private:
  const int  number;
  const float height;
public:
  // MyClass():number(1358), height(1.58){  }
  MyClass(): INITIATION { } // Uzun uzun yazı görmek isteiyorsak bu şeklide gizlenebilir.
  int getNumber() const {
    return number;
  }
};

int main(){

  MyClass my_class;
  my_class.getNumber();
  return 0;
}