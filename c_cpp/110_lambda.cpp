#include <iostream>

using namespace std;

int main() {

  auto add = [] (int a, int b) {
   cout << "add() = " << a + b;
  };

  add(100, 78);

  return 0;
}
/*

Bir değişkene ulaşmak için [] içine değişken belirtilmelidir eğer tüm değişkenlerin değelerine ulaşmak için
= işarti eğer odeğerde oyanma yapılacaksa & işareti konulur.

*/