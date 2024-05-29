/*
* "Armstrong" sayısı (Armstrong number), bir sayının basamaklarındaki rakamların küplerinin  
* toplamının kendisine eşit olduğu bir sayıdır. 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
*
* "Palindrome" sayısı, ileriye doğru okunduğunda ve geriye doğru okunduğunda aynı olan bir 
* sayıdır. 131, 12321, 1221...
*/

#include <stdio.h>
#include <math.h>

int number;
int backup, sum;

int isArmstrongNumber(int number);
int isPolindrome(int);
int reverseNumber(int);

int main(){
    printf("Input:  ");
    scanf("%d", &number);
    
    printf("%srmstrong\n", (isArmstrongNumber(number) == 1 ? "A" : "Not a"));
    printf("%salindrome number.\n", (isPolindrome(number) == 1 ? "P": "Not p"));
    return 0;
}

int isArmstrongNumber(int number){
    backup = number;
    while (backup > 0){
        int digit = backup % 10;
        sum += digit * digit * digit; //pow(digit, 3);
        backup = backup / 10;
    }    
    return (sum == number ? 1 : 0);
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