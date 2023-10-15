/*
* Fibonacci series is made using loop 
* and using recursion feature
*/

#include "stdio.h"

int number;
int fib[2] = {0, 1}; 
int results = 0;

void fibonacci(int);
void fibonacciRecursion(int);

int main(int args, char* argv[]){
    printf("Input:  ");
    scanf("%d", &number);
    printf("Output: ");
    // fibonacci(number);
    fibonacciRecursion(number);
    return 0;
}

void fibonacci(int number){
    for(int i = 0; i < number; i++){
        printf("%d, ", results);
        if(i < 1){ 
            results = fib[1];
            continue; 
        }
        results = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = results;
    }
    printf("\n");
}

void fibonacciRecursion(int number){
    static int count = 0;
    if(number == 0){
        printf("\n");
        return;
    }
    printf("%d, ", results);
    results = fib[0] + fib[1];
    fib[0] = fib[1];
    fib[1] = results;
    if(count < 1){
        fib[0] = 0;
    }
    count++;
    fibonacciRecursion(number - 1);
}