/*
* decimal to binary
*/

#include <stdio.h>

int number;
int binary[32];

void decimalToBinary(int);

int main(){
    printf("Enter a decimal number: ");
    scanf("%d", &number); 
    decimalToBinary(number);
}

void decimalToBinary(int number){
    int i = 0;
    while(number > 0){
        binary[i++] = number % 2;
        number /= 2;
    }

    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}
