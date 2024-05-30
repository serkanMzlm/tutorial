#include <stdio.h>
#include <stdarg.h>

int add(int, ...);
int obeb(int , int );
int okek(int , int );
long int factorial(int);
void getArray(int array[][3], int column, int colon);
void echo(int a, int b);

int array_1[4][3] = 
{
  {1, 0, 3}, {2, 4, 5},
  {3, 5, 2}, {7, 9, 0}
};

int dizi[3] = {1, 2, 39};
void (*funcPtr)(int, int) = &echo;  // Fonksiyona bellek alanı üzerinden erişmek

int main(){

  printf("obeb(250, 10): %d\n", obeb(250, 10));
  printf("okek(80, 40): %d\n", obeb(80, 40));
  printf("add(80, 40): %d, add(1, 2, 5, 89): %d\n", add(2, 80, 40), add(4, 1, 2, 5, 89));
  printf("5! : %ld\n", factorial(5));
  printf("______________________\n");
  getArray(array_1, 4, 3);
  printf("%d\n", 1[dizi]);
  printf("%d\n", dizi[1]);
  (*funcPtr)(19, 20);
  return 0; 
}

int add(int value, ...) {
    int sum = 0;

    va_list args;
    va_start(args, value);

    for (int i = 0; i < value; i++) {
        int num = va_arg(args, int);
        sum += num;
    }

    va_end(args);

    return sum;
}


int obeb(int a, int b ){
  for(int i = (a > b ? b : a); i > 0; i--){
    if((a  % i == 0) && (b % i == 0)){
      return i;
    } 
  }
  return 0;
}

int okek(int a, int b){
  if((a > b ? a : b) % (a > b ? b : a) == 0){
    return (a > b ? a : b);
  }
  for(int i = (a > b ? a : b); ; i += (a > b ? a : b)){
    if((i % a == 0) && (i % b == 0)){
      return i;
    }
  }
  return 0;
}

void getArray(int array[][3], int column, int colon){
  for(int i = 0; i < column; i++){
    for(int j = 0; j < colon; j++){
      printf("%d  ", array[i][j]);
    }
    printf("\n");
  }
}

long int factorial(int value){
  if(value == 0 || value == 1){
    return 1;
  }
  return (value * factorial(value - 1)); 
}

void echo(int a, int b) {
    printf("\n%d - %d\n", a, b);
}