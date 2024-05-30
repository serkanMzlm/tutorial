#include <stdio.h>
#include "info_messages.h"

int array[10];

void setArray(int array[], int number);
void sortData(int array[], int number);
void getData(int array[], int number);

int main()
{
	int array_long;
	DEBUG("The number you enter must be between 0 and 10.");
	printf("Please, insert the size of your array: ");
	scanf("%d", &array_long);
	if (array_long < 0 || array_long > 10)
	{
		ERROR("You entered an invalid value!");
		return -1;
	}
	setArray(array, array_long);
	sortData(array, array_long);
	getData(array, array_long);
	return 0;
}

void setArray(int array[], int number)
{
	for (int i = 0; i < number; i++)
	{
		printf("%d. Number: ", i + 1);
		scanf("%d", &array[i]);
	}
}

void sortData(int array[], int number)
{
	int backup;
	for (int j = 0; j < number; j++)
	{
		for (int i = 0; i < number - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				backup = array[i + 1];
				array[i + 1] = array[i];
				array[i] = backup;
			}
		}
		for (int i = number - 1; i > 0; i--)
		{
			if (array[i] < array[i - 1])
			{
				backup = array[i - 1];
				array[i - 1] = array[i];
				array[i] = backup;
			}
		}
	}
}

void getData(int array[], int number)
{
	DEBUG("_____________________________________________");
	for (int i = 0; i < number; i++)
	{
		printf("%d. Number : %d\n", i + 1, array[i]);
	}
	DEBUG("_____________________________________________");
}