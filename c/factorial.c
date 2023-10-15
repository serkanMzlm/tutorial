/*
* A factorial is a number that can be multiplied to  
* another number to produce a specific result. 
*/
#include <stdio.h>

int number, factorial_number = 1;

int factorial(int);

int main(){
    printf("Input:  ");
    scanf("%d", &number);
    printf("The Factorial of %d is: %d\n", number, factorial(number));

    return 0;
}

int factorial(int number){
    if(number == 0){
        return factorial_number;
    }
    factorial_number *= number;
    factorial(number - 1);
}