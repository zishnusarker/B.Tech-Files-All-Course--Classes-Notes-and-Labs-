#include <stdio.h>
#include <stdlib.h>

void bubblesort(int a[],int n)
{
    int temp,i,j;
    for( i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}

int main()
{
    int arr[10];
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of an array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Sorted array\n");
    bubblesort(arr,n);

    return 0;
}
