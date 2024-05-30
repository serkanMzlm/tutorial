#include <stdio.h>
#pragma once
#define DEBUG_1
#define PI 3.13
#define SQUARE(value) value*value
#define MAX(x , y) (x) < (y) ?  (y) : (x)


int main(){
  SQUARE(5);
  #ifndef DEBUG_1
  MAX(20, 30);
  #elif DEBUG_2
  MAX(20, 40);
  #else
  MAX(1,-1);
  #endif
  #undef DEBUG_1
  return 0;
}