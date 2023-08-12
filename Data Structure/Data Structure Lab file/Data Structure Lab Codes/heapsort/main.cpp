#include <stdio.h>
#include<stdlib.h>

  void swap(int *x, int *y)
  {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
      largest = l;

    if (r < n && arr[r] > arr[largest])
      largest = r;


    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }

  // Main function to do heap sort
  void heapSort(int arr[], int n)
   {
      for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

  // Print an array
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

  // Driver code
  int main() {
    int array[10],n;
    printf("Enter the number of elements that you want to enter:");
    scanf("%d",&n);
    printf("Enter the elements of an array:\n");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&array[i]);
    }
    heapSort(array, n);
    printf("Sorted array is \n");
    printArray(array, n);
  }
