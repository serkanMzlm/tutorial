#include "stdio.h"

int number = 1;
int fib[2] = {1, 1}; 
int results = 0;
void fibonacci(int);

int main(int args, char* argv[]){
    printf("Input:  ");
    scanf("%d", &number);
    printf("Output: ");
    fibonacci(number);
    return 0;
}

void fibonacci(int number){
    for(int i = 0; i < number; i++){
        printf("%d, ", results);
        if(i <= 1){ 
            results = fib[0];
            continue; 
        }
        results = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = results;
    }
    printf("\n");
}