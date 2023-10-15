/*
* An Armstrong number (or narcissistic number) is a number that is equal to the sum 
* of its own digits raised to the power of the number of digits in that number.
*/
#include <stdio.h>
#include <math.h>

int number;
int backup, sum;

int isArmstrongNumber(int number);
int main(){
    printf("Input:  ");
    scanf("%d", &number);
    printf("%srmstrong\n", (isArmstrongNumber(number) == 1 ? "A" : "Not a"));
    return 0;
}

int isArmstrongNumber(int number){
    backup = number;
    while (backup > 0){
        int digit = backup % 10;
        sum += pow(digit, 3);
        backup = backup / 10;
    }    
    return (sum == number ? 1 : 0);
}