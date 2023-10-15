#include <stdio.h>

int sum, number;

int sumOfDigits(int number);

int main(){
    printf("Input:  ");
    scanf("%d", &number);
    printf("The sum digits of %d is: %d\n", number, sumOfDigits(number));
    return 0;
}

int sumOfDigits(int number){
    while (number > 0){
        int digit = number % 10;
        sum += digit;
        number = number / 10;
    } 

    return sum;
}