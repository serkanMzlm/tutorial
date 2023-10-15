/*
* Code to check whether the entered number is a palindrome.
* A palindrome is a number ar word that reads the same forwards and backwards.
* Example: 131, 12321, 1221...
*/
#include <stdio.h>

int number = 0;

int isPolindrome(int);
int reverseNumber(int);
int main(){
    printf("Enter the number to be checked: ");
    scanf("%d", &number);
    printf("%salindrome number.\n", (isPolindrome(number) == 1 ? "P": "Not p"));
    return 0;
}

int isPolindrome(int number){
    int reverse = reverseNumber(number);
    return (reverse == number ? 1 : 0);
}

int reverseNumber(int number){
    int reverse = 0, remainder = 0;
    while (number > 0){
        remainder = number % 10;
        reverse = reverse*10 + remainder;
        number /= 10;
    }
    return reverse;    
}