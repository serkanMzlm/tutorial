#include <stdio.h>
#include<stdlib.h>  

int number;

int main() {
    char currentChar;
    system("clear"); // windows => system("cls");    
    printf("Enter the number of rows: ");
    scanf("%d", &number);
    for (int i = 1; i <= number; i++) {
        for (int space = 0; space < number - i; space++) {
            printf(" ");
        }
        currentChar = 'A';
        for (int j = 1; j <= i; j++) {
            printf("%c", currentChar);
            currentChar++;
        }
        currentChar--;
        for (int j = 1; j <= i - 1; j++) {
            currentChar--;
            printf("%c", currentChar);
        }
        printf("\n");
    }
    return 0;
}
