#include <stdio.h>

int array[] = {1, 2, 3, 4, 5, 12, 36, 12, 298, 76, 71, 23};
int sequentialSearch(int search);
int binarySearch(int arr[], int left, int right, int search);
void bubbleSort(int arr[], int n);

int main()
{
  bubbleSort(array, (sizeof(array) / sizeof(array[0])));
  sequentialSearch(2);
  int n = sizeof(array) / sizeof(array[0]);
  int key = 24;
  binarySearch(array, 0, n - 1, key);

  return 0;
}

int sequentialSearch(int search)
{
  for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++)
  {
    if (array[i] == search)
    {
      printf("Found at index %d\n", i);
      return 1;
    }
  }
  return 0;
}

int binarySearch(int arr[], int left, int right, int search)
{
  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (arr[mid] == search)
      return mid;

    if (arr[mid] < search)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

void bubbleSort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] < arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
