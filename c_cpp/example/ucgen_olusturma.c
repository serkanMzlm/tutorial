#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 26
#define MIN_VALUE 0

int max(int a, int b);
int min(int a, int b);
int map(int number);

void lettersTriangle(int step_size);
void numbersTriangle(int step_size);
void fibonacciTriangle(int step_size);
void fibonacci(int step_size);

int choice;
int results, count;
int fib[2] = {0, 1};

int main()
{
    int row;
    system("clear"); // windows => system("cls");
    printf("Enter the number of rows (0-26): ");
    if (!scanf("%d", &row))
    {
        return -1;
    }

    printf("Number(0) or Letter(1) or finonacci(2): ");
    if (scanf("%d", &choice))
    {
        switch (choice)
        {
        case 0:
            numbersTriangle(row);
            break;
        case 1:
            lettersTriangle(row);
            break;
        case 2:
            fibonacciTriangle(row);
            break;
        default:
            break;
        }
    }

    return 0;
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

// Harflerden Üçgen Oluşturur.
void lettersTriangle(int step_size)
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

// Sayılardan Üçgen Oluşturur.
void numbersTriangle(int step_size)
{
    int count;
    for (int i = 1; i <= step_size; i++)
    {
        for (int space = 0; space < step_size - i; space++)
        {
            printf(" ");
        }
        count = 1;
        for (int j = 1; j <= i; j++)
        {
            printf("%d", count);
            count++;
        }
        count--;
        for (int j = 1; j <= i - 1; j++)
        {
            count--;
            printf("%d", count);
        }
        printf("\n");
    }
}

// Fibonaci dizini olarak üçgen oluşur.
void fibonacciTriangle(int step_size)
{
    for (int i = 0; i < step_size; i++)
    {
        fibonacci(i);
        fib[0] = results = count = 0;
        fib[1] = 1;
    }
}

void fibonacci(int step_size)
{
    if (step_size == 0)
    {
        printf("\n");
        return;
    }

    printf("%d, ", results);
    results = fib[0] + fib[1];
    fib[0] = fib[1];
    fib[1] = results;
    count++;
    fibonacci(step_size - 1);
}
