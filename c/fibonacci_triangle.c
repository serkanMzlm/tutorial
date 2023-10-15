// fibonacci triangle
#include <stdio.h>

int number, results;
int count;
int fib[2] = {0, 1}; 

void fibonacci(int);
void triangle(int);

int main(){
    printf("Input:  ");
    scanf("%d", &number);
    triangle(number);
    return 0;
}

void fibonacci(int number){
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
    fibonacci(number - 1);
}

void triangle(int number){
    for(int i = 0; i < number; i++){
        fibonacci(i);
        fib[0] = results = count = 0;
        fib[1] = 1;
    }
}