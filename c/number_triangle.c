#include <stdio.h>
#include <stdlib.h>  

int number;
int count;

void printTriangle(int number);
int main() {
    system("clear"); // windows => system("cls");    
    printf("Enter the number of rows: ");
    scanf("%d", &number);
    printTriangle(number);    
    return 0;
}

void printTriangle(int number){
    for (int i = 1; i <= number; i++) {
        for (int space = 0; space < number - i; space++) {
            printf(" ");
        }
        count = 1;
        for (int j = 1; j <= i; j++) {
            printf("%d", count);
            count++;
        }
        count--;
        for (int j = 1; j <= i - 1; j++) {
            count--;
            printf("%d", count);
        }
        printf("\n");
    }
}