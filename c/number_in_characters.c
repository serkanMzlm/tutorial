#include <stdio.h>
#include <stdlib.h>  

int number, reversed_number;

void characters(int);
void digits(int);

int main(){
    system("clear"); // windows => system("cls");   
    printf("Input:  ");
    scanf("%d", &number);
    digits(number);
    return 0;
}

void characters(int number){
    switch (number){
        case 0:
            printf("zero ");
            break;
        case 1:
            printf("one ");
            break;
        case 2:
            printf("two ");
            break;
        case 3:
            printf("three ");
            break;
        case 4:
            printf("four ");
            break;
        case 5:
            printf("five ");
            break;
        case 6:
            printf("six ");
            break;
        case 7:
            printf("seven ");
            break;
        case 8:
            printf("eight ");
            break;
        case 9:
            printf("nine ");
            break;
        default:
            break;
    }
}

void digits(int number){
    printf("_______________\n");
    while(number > 0){
        int digit = number % 10;
        reversed_number = reversed_number  * 10 + digit;
        number = number / 10;
        characters(digit);
    }
    printf("\n_______________\n");
    while(reversed_number > 0){
        int digit = reversed_number % 10;
        characters(digit);
        reversed_number /= 10;
    }
    printf("\n");
}