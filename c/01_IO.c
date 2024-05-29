#include <stdio.h>

char ch, mem;

void sprintfSscanfInfo();
void getcharPuthcharInfo();
void printfInfo();

int main()
{
  printf("________________________________\n");
  printfInfo();
  printf("________________________________\n");
  getcharPuthcharInfo();
  printf("________________________________\n");
  sprintfSscanfInfo();
  printf("________________________________\n");
  return 0;
}

void sprintfSscanfInfo()
{
  char char_array[50];
  int a, b, c;
  char number[] = "42 65 78";

  sprintf(char_array, "Ali %d", 10);      // karakter dizini belirtilen dizine atanır.
  sscanf(number, "%d %d %d", &a, &b, &c); // Karakter dizininda bulunan tamsayılar alınır.

  printf("sprintf ile oluşturulan karakter dizisi: %s\n", char_array);
  printf("sscanf ile alınan tamsayılar: %d, %d, %d\n", a, b, c);
}

void getcharPuthcharInfo()
{
  printf("Enter a char: ");
  ch = getchar();
  putchar(ch); // Bellekte bulunan ilk veriyi alır.
  printf("\n");
  while ((mem = getchar()) != '\n') // Tamponda kalan veriyi silmeyi sağlar.
  { 
    printf("free: %c\n", mem);
  }
}

void printfInfo()
{
  float number = 3.2109;
  unsigned int number_2 = 12;
  printf("%7.3f \n", number);
  printf("%-7.3f\n", number);
  printf("%+2.3f\n", number);
  printf("%*.*f\n", 2, 3, number); // '*' verilerin dışardan doldurulmasını sağlar.
  printf("%o\n", number_2);
  printf("%x\n", number_2);
  printf("%#04x\n", number_2); // '#' sayının 0x şeklinde yazılmasını sağlar
}