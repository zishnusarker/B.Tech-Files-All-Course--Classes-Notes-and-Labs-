#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *createlist(struct node *start);
void displaylist(struct node *start);
void countnodes(struct node *start);
void search(struct node *start,int x);
struct node *insertinbeginning(struct node *start,int data);
void insertatend(struct node *start,int data);
void insertafter(struct node *start,int data,int x);
struct node *insertbefore(struct node *start,int data,int x);
struct node *insertatposition(struct node *start,int data,int k);
struct node *deletenode(struct node *start,int data);
struct node *reverselist(struct node *start);

main()
{
	struct node *start=NULL;
	int choice,data,x,k;

	start=createlist(start);

	while(1)
	{
		printf("\t\t\t\n------------------Menu------------------\n");
		printf("\t\t\t 1.No of nodes            	   			\n");
		printf("\t\t\t 2.Display list Count     				\n");
		printf("\t\t\t 3.Search for an element     				\n");
		printf("\t\t\t 4.Add to empty list/add at the beginning \n");
		printf("\t\t\t 5.Add a node at the end of the list      \n");
		printf("\t\t\t 6.Add a after a specefied node		    \n");
		printf("\t\t\t 7.Add a before a specefied node  		\n");
		printf("\t\t\t 8.Add a node at a given position  	    \n");
		printf("\t\t\t 9.Delete a node     						\n");
		printf("\t\t\t 10.Quit									\n");

		printf("ENTER YOUR CHOICE: ");
		scanf(" %d ", &choice);

		if(choice==10)
			break;

		switch(choice)
		{
			case 1:
				displaylist(start);
				break;
			case 2:
				countnodes(start);
				break;
			case 3:
				printf("Enter element you want to search");
				scanf(" % d",&data );
				search(start,data);
				break;
			case 4:
				printf("Enter an element you want to insert: ");
				scanf(" %d ",&data);
				start=insertinbeginning(start,data);
				break;
			case 5:
				printf("Enter element you want to enter: ");
				scanf("%d",&data);
				insertatend(start,data);
				break;
			case 6:
				printf("Enter element you want to enter: ");
				scanf("%d",data);
				printf("enter the element after which you want to insert: ");
				scanf("%d",&x);
				insertafter(start,data,x);
				break;
			case 7:
				printf("Enter element you want to enter: ");
				scanf("%d",data);
				printf("enter the element before which you want to insert: ");
				scanf("%d",&x);
				start=insertbefore(start,data,x);
				break;
			case 8:
				printf("Enter element you want to enter: ");
				scanf("%d",data);
				printf("enter the position at which to insert: ");
				scanf("%d",&k);
				start=insertatposition(start,data,k);
				break;
			case 9:
				printf("Enter the element you want to delete: ");
				scanf("%d", &x);
				start=deletenode(start,x);
				break;
			default:
				printf("  INVALID CHOICE ");
		}
	}
}


struct node *createlist(struct node *start)
{
	int i,n,data;

	printf("Enter the number of nodes : ");
	scanf("%d",&n);

	if(n==0)
		return start;

	printf("\nEnter the first element to be inserted \n");
	scanf("%d",&data);

	start=insertinbeginning(start,data);

	for(i=2; i<=n; i++)
	{
		printf("Enter the next elements to be inserted \n ");
		scanf("%d",&data);
		insertatend(start,data);

	}
	return start;
}

struct node *insertinbeginning(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;

	temp->link=start;
	start=temp;

	return start;
}

void insertatend(struct node *start,int data)
{
	struct node *p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;

	p=start;
	while(p->link!=NULL)
		p=p->link;

	p->link=temp;
	temp->link=NULL;
}

void displaylist(struct node *start)
{
	struct node *p;

	if(start==NULL)
	{
		printf("\n List is empty \n ");
		return;
	}
	printf("List is: ");
	p=start;
	while(p!=NULL)
	{
		printf(" %d ",p->info);
		p=p->link;

	}
	printf(" \n ");

}

void countnodes(struct node *start)
{
	int n=0;
	struct node *p;
	p=start;
	while(p!=NULL)
	{
		n++;
		p=p->link;
	}
	printf("No of nodes in the list are: %d ",n);

}



void insertafter(struct node *start,int data,int x)
{
	struct node *temp,*p;

	p=start;
	while(p!=NULL)
	{
		if(p->info==x)
			break;
		p=p->link;
	}
	if(p==NULL)
		printf("%d not present in the list\n ",x);
	else
	{
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=p->link;
	p->link=temp;
    }
}

struct node *insertbefore(struct node *start,int data,int x)
{
	struct node *temp,*p;

	if(start==NULL)
	{
		printf("list is empty \n");
		return start;
	}

	if(x==start->info)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=start;
		start=temp;

		return start;
	}

	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==x)
			break;
		p=p->link;
	}

	if(p->link==NULL)
		printf("%d not found in the list ",x);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}
	return start;
}

struct node *insertatposition(struct node *start,int data,int k)
{
	struct node *temp,*p;
	int i;

	if(k==1)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=start;
		start=temp;

		return start;
	}

	p=start;
	for(i=1; i<k-1 && p!=NULL; i++)
		p=p->link;

	if(p==NULL)
		printf("you can insert only upto %dth position \n\n",i);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;

	}

		return start;

}

void search(struct node *start,int x)
{
	struct node *p;
	int position=1;

	p=start;
	while(p!=NULL)
	{
		if(p->info==x)
			break;
		position++;
		p=p->link;

	}
	if(p==NULL)
		printf("%d not foung on the list  ", x);
	else
	printf("%d was found at %d positon: ",x,position);
}

struct node *deletenode(struct node *start, int x)
{
	struct node *temp,*p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}

	if(start->info==x)
	{
		temp=start;
		start=start->link;
		free(temp);
		return start;
	}

	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==x)
			break;
		p=p->link;
	}

	if(p->link==NULL)
		printf("Element %d is not in list \n\n",x);
	else
	{
		temp=p->link;
		p->link=temp->link;
		free(temp);
	}
	return start;

}






