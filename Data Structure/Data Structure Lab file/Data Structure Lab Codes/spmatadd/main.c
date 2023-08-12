#include<stdio.h>
#define size 20

struct sparse
{
	int rows , columns , d ;
	int row[size] , col[size], value[size];
};

void readMatrix(struct sparse *P)
{
	int i,a,b,c;

	printf("Enter number of rows: ");
	scanf("%d",&P->rows);

	printf("Enter number of columns: ");
	scanf("%d",&P->columns);

	printf("Enter number of nonzero elements: ");
	scanf("%d",&P->d);

	for(i=0;i<P->d;i++)
	{
		printf("Enter row index, column index and value : ");
		scanf("%d%d%d",&a,&b,&c);

		P->row[i]=a;
		P->col[i]=b;
		P->value[i]=c;
	}

}


void printMatrix(struct sparse Q)
{
	int i,j,k=0;

	for(i=0;i<Q.rows;i++)
	{
		for(j=0;j<Q.columns;j++)
		{
			if((i==Q.row[k])&&(j==Q.col[k]))
			{
				printf("%6d",Q.value[k]);
				k++;
			}

			else
				printf("%6d",0);

		}

		printf("\n");
	}
}
struct sparse addMatrix(struct sparse A, struct sparse B)
{
	struct sparse C;
	int i,j,k;
	i=0;
	j=0;
	k=0;

	while(i<A.d && j<B.d)
	{
		if(A.row[i]==B.row[j]&&A.col[i]==B.col[j])
		{
			if(A.value[i]+B.value[j]!=0)
			{
				C.row[k]=A.row[i];
				C.col[k]=A.col[i];
				C.value[k]=A.value[i]+B.value[j];
				k++;
			}

			i++;
			j++;
		}

		if((A.row[i]<B.row[j])||(A.row[i]==B.row[j]&&A.col[i]<B.col[j]))
		{
			C.row[k]=A.row[i];
			C.col[k]=A.col[i];
			C.value[k]=A.value[i];
			i++;
			k++;
		}

		else
		{
			C.row[k]=B.row[j];
			C.col[k]=B.col[j];
			C.value[k]=B.value[j];
			j++;
			k++;
		}

	}

	while(i<A.d)
	{
		C.row[k]=A.row[i];
		C.col[k]=A.col[i];
		C.value[k]=A.value[i];
		i++;
		k++;
	}

	while(j<B.d)
	{
		C.row[k]=B.row[j];
		C.col[k]=B.col[j];
		C.value[k]=B.value[j];
		j++;
		k++;
	}

	C.rows=A.rows;
	C.columns=A.columns;
	C.d=k;
	return C;
}

int main()
{
	struct sparse A,B;
	printf("For First matrix:\n\n");
	readMatrix(&A);
	printf("\n");
	printf("For Second matrix:\n\n");
	readMatrix(&B);
	printf("\n");
	printf("\n Elements Of Matrix A:\n");
	printMatrix(A);
	printf("\n Elements Of Matrix B:\n");
	printMatrix(B);
	printf("\n Addition Of A & B Matrix : D=A+B:\n");
	printMatrix(addMatrix(A,B));

	return 0;
}
