#include <stdio.h>

int a = 10;

int main()
{
  switch (a)
  {
  case 1:
    printf("odd\n");
    break;
  case 2:
    printf("even\n");
  default:
    printf("number: %d", a);
    break;
  }

  if (a % 2 == 0)
  {
    printf("even\n");
  }
  else if (a % 2 == 1)
  {
    printf("odd\n");
  }

  printf("number: %d, %s\n", a, (a % 2 == 0 ? "even" : "odd"));
  int i = 0;
  while (i < a)
  {
    printf("%d\n", i);
    i++;
    if (i == 2)
    {
      continue;
    }
  }

  do
  {
    printf("%d\n", i);
    i--;
  } while (i > 0);

  for (int j = a; j > 0; j--)
  {
    printf("%d\n", j);
    if (i == 2)
    {
      break;
      ;
    }
  }

  return 0;
}