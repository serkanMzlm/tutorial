#include <stdio.h>

int main(){
  // FILE * file = NULL;
  // file = fopen("test.txt", "w"); //Dosya adı verilirken yol belirtebiliriz.
  FILE * file = open("test.txt", "w"); // Tek satırda yapılabilir.
  if(file == NULL) { return -1;}
  fclose(file);
  return 0;
}