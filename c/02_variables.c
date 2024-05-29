#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include "info_messages.h"

char char_1 = 65;
char* char_2 = "15.48";
char* char_3 = "253";
char char_array[4] = {'A', 65, 'B', 'D'}; // Karakterlerin ASCII sayı karşılıklarıda yazılabilir.

// const sabitlemek için kullanılır
const int number = 20;

float number_1  = (float)(7 / 3);
float number_2  = 7 / 3;
double number_3 = 7 / 3.0;
float number_4  = 7 / (float)3;
float number_5  = (float)7 / 3;

int array[5]   = {[0 ... 4] = 5}; 
int array_2[5] = {[0 ... 2] = 2, [3 ... 4] = 10}; 

void add();
int main(){
  register int rega =10 ;  // Bellekte bir alan tutmadığı için globale yazılmaz
  printf("number_1 = %f\n",number_1);
	printf("number_2 = %f\n",number_2);
	printf("number_3 = %f\n",number_3);
	printf("number_4 = %4f\n",number_4);
	printf("number_5 = %*.2f\n",3,number_5);
  
  printf("int  minimum value : %d\n",INT_MIN); //int ninimum degeri
	printf("int maximum value : %d\n",INT_MAX); //int maksimum degeri
	printf("float minimum value : %.5g\n",FLT_MIN);
	printf("float maximum value : %.5g\n",FLT_MAX);
	printf("double maximum value : %.5Lg\n",DBL_MIN);
	printf("double minimum value : %.5Lg\n",DBL_MAX);

  int char2int = atoi(char_3); //string  int cevirir.
  float char2float = atof(char_2); //string float cevirir.
  printf("number 0 = %d\nnumber 1 = %.2f",char2int, char2float);

  printf("char :%d byte \na array:%d byte\n",sizeof(char), sizeof char_array);  // sizeof(a) veya sizeof a şeklinde bellekte kapladığı alanı görürüz
  printf("signed char (min_value, max_value): (%d, %d)\n",SCHAR_MIN, SCHAR_MAX);
  add();
  add();
  add();
  return 0;
}

void add(){
  int a = 0;
  static int b = 0;
  a++;
  b++;
  printf("a: %d\t|\t static b: %d\n", a, b);
}