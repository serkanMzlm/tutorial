#include <iostream>

using namespace std;
// using std::cout;
// using std::endl;

int number = 10;
int number_1 {20};
string name;
string surname;

namespace user_1{
  int age =  19;
  string name = "Ali";
};
namespace user_2{
  int age =  20;
  string name = "Mert";
};
namespace user_3{
  int age =  30;
  string name = "Burak";
};

int array[3] = {1, 4, 7};

int main(){
// önce yazar sonra degeri bir artirir (postfix)
	cout << "Postfix = " << number_1++ << endl; 
// önce deðeri bir artirir sonra yazar (prefix)
	cout << "Prefix = " << ++number_1 << endl;  

// cin fonksiyonu \n görene kadar veriyi belirtilen değişkene kaydeder.
  cout << "name: ";
  cin>>name;
  // getline fonksiyonu cin fonksiyonundan farkı alabileçeği kısmı 
  // biz belirleriz. Örnek olarak "," kadar alır.
  getline(cin, surname, ',');
  cout<<"name: " << name <<endl;

  cout << "user 1 name:" << user_1::name << " age: " << user_1::age << endl;
  cout << "user 2 name:" << user_2::name << " age: " << user_2::age << endl;
  cout << "user 3 name:" << user_3::name << " age: " << user_3::age << endl;

  cout << array[1] << " = " << 1[array];


  return 0;
}