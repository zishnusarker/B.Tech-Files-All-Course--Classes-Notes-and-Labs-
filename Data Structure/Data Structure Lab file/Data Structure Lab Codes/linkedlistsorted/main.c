#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
};

struct node *InsNode(struct node *s,int x)
{
	struct node *p,*q;
	q=(struct node*)malloc(sizeof(struct node));

	q->value=x;

	if(s==NULL)
	{
		s=q;
		q->next=NULL;
	}

	else if(x<s->value)
	{
		q->next=s;
		s=q;
	}

	else
	{
		p=s;

		while(p->next!=NULL&&x>p->next->value)
		{
			p=p->next;
		}

		q->next=p->next;
		p->next=q;
	}

	return(s);
}

struct node* DelNode(struct node *s,int x)
{
	struct node *p;

	if(s==NULL)
	{
		return(s);
	}

	p=s;

	if(p->value==x)
	{
		p=p->next;
		s=p;


		return(s);
	}

	while(p->next != NULL && p->next->value!=x )
	{
		p=p->next;
	}

	if(p->next == NULL)
	{
		printf("Element does not exist.\n");
		return s;
	}

	p->next=p->next->next;
	printf("Operation succeeded.\n");


	return(s);
}

void LSearch(struct node *s,int x)
{
	int pos=1;
	struct node *p;

	p=s;

	while(p->value!=x)
	{
		p=p->next;
		pos++;
	}

	if(p->value==x)
	{
		printf("Element found at position %d.\n",pos);
		return;
	}
	else
		printf("Element not found.\n");

}

void LCount(struct node *s)
{
	int n;
	struct node *p;

	p=s;

	printf("List of elements:\n");

	while(p!=NULL)
	{
		printf("%d , ",p->value);
		p=p->next;
		n++;
	}

	printf("Total elements: %d\n",n);
}


int main()
{
	struct node *start;
	start=NULL;
	int ch,x,y;

	while(1)
	{
		printf("\nList of operations:\n");
		printf("1. Insert element\n");
		printf("2. Delete element\n");
		printf("3. Search element\n");
		printf("4. Count and display elements\n");
		printf("5. Exit\n");

		printf("Enter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d",&x);
				start=InsNode(start,x);
				printf("Operation succeeded.\n");
				break;

			case 2:
				printf("Enter element to be deleted: ");
				scanf("%d",&x);
				start=DelNode(start,x);
				break;

			case 3:
				printf("Enter element to be searched: ");
				scanf("%d",&x);
				LSearch(start,x);
				break;

			case 4:
				LCount(start);
				break;

			case 5:
				printf("Thank you.");
				return 0;
				break;

			default:
				printf("Invalid choice!\n");
				break;
		}
	}

}
