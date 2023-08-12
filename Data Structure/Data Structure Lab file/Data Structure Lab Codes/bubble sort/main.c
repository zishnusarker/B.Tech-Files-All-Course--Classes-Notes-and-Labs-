#include <stdio.h>

int main()
{
  int array[100], a, i, j, swap;

  printf("Enter number of elements\n");
  scanf("%d", &a);

  printf("Enter %d integers\n", a);

  for (i=0; i<a; i++)
    scanf("%d", &array[i]);

  for (i=0 ; i<a-1; i++)
  {
    for (j=0 ; j<a-i-1; j++)
    {
      if (array[j] > array[j+1])
      {
        swap       = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order :\n");

  for (i = 0; i < a; i++)
     printf("%d ", array[i]);

  return 0;
}
