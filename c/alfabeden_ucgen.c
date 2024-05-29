#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 26
#define MIN_VALUE 0

void printTriangle(int step_size);
int max(int a, int b);
int min(int a, int b);
int map(int number);

int main()
{
    int row;
    system("clear"); // windows => system("cls");
    printf("Enter the number of rows (0-26): ");
    if (scanf("%d", &row))
    {
        printTriangle(row);
    }
    return 0;
}

void printTriangle(int step_size)
{
    char current_char;
    step_size = map(step_size);

    for (int i = 1; i <= step_size; i++)
    {
        for (int space = 0; space < step_size - i; space++)
        {
            printf(" ");
        }

        current_char = 'A';
        for (int j = 1; j <= i; j++)
        {
            printf("%c", current_char);
            current_char++;
        }

        current_char--;
        for (int j = 1; j < i; j++)
        {
            current_char--;
            printf("%c", current_char);
        }
        printf("\n");
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int map(int number)
{
    max(MIN_VALUE, min(number, MAX_VALUE));
}