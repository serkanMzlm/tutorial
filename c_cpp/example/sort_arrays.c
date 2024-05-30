#include <stdio.h>
int main()
{
	int array[4] = {9, 3, 6, 1};
	printf("Start: ");
	for (int a = 0; a < 4; a++)
	{
		printf("%d ", array[a]);
	}
	for (int b = 0; b < 3; b++)
	{

		for (int i = 0; i < 3 - b; i++)
		{
			if (array[i] > array[i + 1])
			{
				int passive = array[i];
				array[i] = array[i + 1];
				array[i + 1] = passive;
			}
		}
		printf("\n%d. State : ", b + 1);
		for (int i = 0; i < 4; i++)
		{
			printf("%d ", array[i]);
		}
	}
	return 0;
}
