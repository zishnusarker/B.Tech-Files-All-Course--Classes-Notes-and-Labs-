#include <stdio.h>
#include <stdlib.h>
int size=0;
void swap(int *x,int *y)
{
    int temp= *y;
    *y = *x;
    *x =temp;
}

//function to create a heap
void heapify(int array[],int size,int i)
{
    if(size==1)
    {
        printf("Only one element in the heap\n");
    }
    else{
    int largest=i;
    int l= 2*i+1;
    int r=2*i+2;
    if(l<size&&array[l]>array[largest])
        largest=l;
     if(r<size&&array[r]>array[largest])
        largest=r;
    if(largest!=i)
    {
        swap(&array[i],&array[largest]);
    heapify(array,size,largest);
    }
    }
    }

void insert(int array[],int data)
{
    if(size==0)
    {
        array[0]=data;
        size+=1;
    }
    else
    {
        array[size]=data;
        size+=1;
        //to convert array into heap
        for(int i=size/2-1;i>=0;i--)
        {
        heapify(array,size,i);
        }
    }
}
void deletee(int array[],int data)
{
    int i;
    for( i=0;i<size;i++)
    {
        if(data==array[i])
        break;
    }
   swap(&array[i],&array[size-1]);
    size-=1;
for(int i=size/2-1;i>=0;i--){
    heapify(array,size,i);
}
}

void printarray(int array[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d  ",array[i]);
       printf("\n");

}

int main()
{
    int array[10],num,data;
    int choice;
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                printf("Enter the number you want to insert:");
                scanf("%d",&num);
                insert(array,num);
                break;
                }
            case 2:
                {
                printf("Enter the number you want to delete:");
                scanf("%d",&data);
                deletee(array,data);
                break;
                }
            case 3:
                {
                printf("The elements of the heap are:");
                printarray(array,size);
                }
            }
      }
  }
