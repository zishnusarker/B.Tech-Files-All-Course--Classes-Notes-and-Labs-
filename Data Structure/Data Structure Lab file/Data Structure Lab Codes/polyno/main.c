#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 20
int n,coff1,poww1,coff2,poww2;
int arr1[CAPACITY];
int arr2[CAPACITY];


void initializefirst()
{
    poww1=n;
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the coefficient of x^%d: ",poww1);
        scanf("%d",&coff1);
        arr1[i]=coff1;
        poww1--;
    }

}

void displayfirst()
{
    poww1=n;
   for(int i=0;i<n;i++)
   {
        if(i==n-1)
       {
           printf(" %dx^%d ",arr1[i],poww1);
       }
       else
       {
           printf(" %dx^%d + ",arr1[i],poww1);
       }

       poww1--;
   }
}

void initializesecond()
{

    poww2=n;
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the coefficient of x^%d: ",poww2);
        scanf("%d",&coff2);
        arr2[i]=coff2;
        poww2--;
    }

}

void displaysecond()
{
    poww2=n;
   for(int i=0;i<n;i++)
   {
       if(i==n-1)
       {
           printf(" %dx^%d ",arr2[i],poww2);
       }
       else
       {
           printf(" %dx^%d + ",arr2[i],poww2);
       }

       poww2--;
   }
}
void add()
{
    int add[n];
    int pow3=n;
    for(int i=0;i<n;i++)
    {
        add[i]=arr1[i]+arr2[i];
    }
    printf("\nAddition is: ");
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
            printf(" %dx^%d",add[i],pow3);
        else
        {
        printf(" %dx^%d + ",add[i],pow3);
        pow3--;
        }

    }

}

void multiply()
{
   int pow1=n;
   int pow2=n;
   printf("\nMultiplication is: ");
    for(int i=0;i<n;i++)
    {


        for(int j=0;j<n;j++)
        {
            if(i==n-1 && j==n-1)
                printf(" %dx^%d ",arr1[i]*arr2[j],pow1+pow2);
            else
            {
            printf(" %dx^%d + ",arr1[i]*arr2[j],pow1+pow2);
            pow2--;
            }

        }
        pow2=n;
        pow1--;
    }
}



int main()
{
    printf("Enter the highest power of two polynomial: ");
    scanf("%d",&n);
    printf("\nInitialize First polynomial: \n");
    initializefirst();
    displayfirst();
    printf("\nInitialize Second Polynomial: \n");
    initializesecond();
    displaysecond();
    add();
    multiply();
    return 0;
}
