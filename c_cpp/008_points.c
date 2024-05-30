#include <stdio.h>

void hello();
int add(int a, int b);

int main()
{
  void (*funcPtr)();       // void dönüş türü ve parametresi olmayan bir fonksiyonun işaretçi tipi
  int (*addPtr)(int, int); // int dönüş türü ve iki int parametresi olan bir fonksiyonun işaretçi tipi

  funcPtr = hello;
  addPtr = add;
  funcPtr(); // hello fonksiyonunu çağırma
  int result = addPtr(3, 5);
  printf("Result: %d\n", result);

  // Global alanda yapılacaksa pointer oluşturma sırasında atama yapılması lazımdır.
  int *ptr = NULL;
  int value = 10;
  ptr = &value;

  printf("ptr address: %p, ptr: %d\n", ptr, *ptr);

  int x = 10;
  int y = 20;

  const int *ptr1 = &x; // İşaretçinin değeri değiştirilebilir, ancak gösterdiği değer değiştirilemez
  // *ptr1 = 15; // Hata! Gösterilen değeri değiştirmeye çalışıyoruz
  ptr1 = &y;            // İşaretçiyi farklı bir bellek konumuna yönlendirebiliriz
  int *const ptr2 = &x; // İşaretçinin değeri değiştirilemez, ancak gösterilen değer değiştirilebilir
  *ptr2 = 15;           // Gösterilen değeri değiştirebiliriz
  printf("ptr2: %d\n", *ptr2);
  printf("ptr1: %d\n", *ptr1);

  return 0;
}

void hello()
{
  printf("Hello!\n");
}

int add(int a, int b)
{
  return a + b;
}