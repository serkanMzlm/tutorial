#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
  int value = 0, sum = 0;
  printf("how many numbers to enter: ");
  scanf("%d", &value);

  int *number_array = (int*)malloc(sizeof(int) * value);
  // calloc bu iki satırın yaptıgını yapar. Belleği oluşturup 0 değeri atar.
  memset(number_array, 0, value*sizeof(int)); // Bellekteki değeler 0 eşitlendi.
  for(int i = 0; i < value; i++){
    printf("enter number %d: ", i);
    scanf("%d", &number_array[i]);
  }

  for(int i = 0; i < value; i++){
    sum += number_array[i];
  }
  int* ptr = (int*)calloc(10, sizeof(int));
  int* ptr_2 = (int*)realloc(ptr, 2*value*sizeof(int));

  free(number_array);
  free(ptr_2);
  free(ptr);
  
  return 0;
}