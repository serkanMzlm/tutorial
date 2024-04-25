#include <stdio.h>

int number;
char ch;
char mem;
char name[20];

int main(){
  printf("Enter a char: ");
  ch = getchar();
  putchar(ch);  
  
  // Tampon belleği boşaltmak için yapılır.
  // putchar sadece bellekte bulunan ilk kısmı
  // alır. kalan kısımları bu şekilde boşaltılabilir.
  printf("\n________________________________\n");
  while ((mem = getchar()) != '\n') { 
    printf("free: %c\n", mem);
    continue;  
  }

  printf("Enter a char: ");
  printf("char : %c\nEnter a number: ", getchar());
  scanf("%d", &number);
  printf("number: %d\n", number);
  puts("what is your name: ");
  fgets(name, sizeof(name), stdin);
  puts(name);
  return 0;
}