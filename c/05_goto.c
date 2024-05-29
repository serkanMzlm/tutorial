#include <stdio.h>

int main()
{
	int a = 0;

again:
	a++;
	printf("a = %d\n", a);

	if (a < 10)
	{
		goto again; // gidilemsini istenilen yer yazılır
	}

	return 0;
}
