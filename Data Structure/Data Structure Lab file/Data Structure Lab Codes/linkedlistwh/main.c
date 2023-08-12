
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

void createlist(struct node *head);
void displaylist(struct node *head);
void insertatend(struct node *head,int data);
void insertbefore(struct node *head,int data,int x);
void insertatposition(struct node *head,int data,int k);
void deletenode(struct node *head,int data);
void countnodes(struct node *head);


main()
{
	int x,choice,k,data;
	struct node *head;

	head=(struct node *)malloc(sizeof(struct node));
	head->info=0;
	head->link=NULL;

	createlist(head);

	while(1)
	{
		printf("\n\n\t\t\t   ---------------MENU--------------- 	\n ");
		printf("\t\t\t 1.Display list  							\n ");
		printf("\t\t\t 2.Insert a node at the end of the list   \n ");
		printf("\t\t\t 3.Insert a new node before a node 		\n ");
		printf("\t\t\t 4.Insert at a given postion 				\n ");
		printf("\t\t\t 5.Delete a node 							\n ");
		printf("\t\t\t 6.Count the no. of nodes					\n ");
		printf("\t\t\t 7.EXIT									\n ");

		printf("\nENTER  YOUR  CHOICE : ");
		scanf("%d",&choice);

		if(choice==7)
			break;

		switch(choice)
		{
			case 1:
				displaylist(head);
				break;
			case 2:
				printf("Enter the element to be inserted: ");
				scanf("%d",&data);
				insertatend(head,data);
				break;
			case 3:
				printf("Enter the element to be inserted: ");
				scanf("%d",&data);
				printf("Enter the element before which to inserted: ");
				scanf("%d",&x);
				insertbefore(head,data,x);
				break;
			case 4:
				printf("Enter the element to be inserted: ");
				scanf("%d",&data);
				printf("Enter the postion before which to insert: ");
				scanf("%d",&k);
				insertatposition(head,data,k);
				break;
			case 5:
				printf("Enter the element to delete: ");
				scanf("%d",&data);
				deletenode(head,data);
				break;
			case 6:
				countnodes(head);

			default:
				printf("Invalid choice");
		}
	}


}
void insertatend(struct node *head, int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;

	p=head;
	while(p->link!=NULL)
		p=p->link;

	p->link=temp;
	temp->link=NULL;

}

void createlist(struct node *head)
{
	int i,n,data;

	printf("Enter the number of nodes: ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("\nEnter the element to be inserted: ");
		scanf("%d",&data);
		insertatend(head,data);
	}
}



void displaylist(struct node *head)
{
	struct node *p;
	if(head->link==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=head->link;
	printf("List is: ");
	while(p!=NULL)
	{
		printf(" %d ",p->info);
		p=p->link;
	}
	printf("\n");
}


void insertatposition(struct node *head,int data,int k)
{
	struct node *temp,*p;
	int i;

	p=head;
	for(i=1; i<=k-1 && p!=NULL; i++)
		p=p->link;

	if(p==NULL)
		printf("You can insert only upto %dth position\n\n",i-1);
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;
	}

}

void deletenode(struct node *head, int data)
{
	struct node *temp,*p;

	p=head;
	while(p->link!=NULL)
	{
		if(p->link->info==data)
			break;
		p=p->link;
	}
	if(p->link==NULL)
		printf("Element %d not found \n",data);
	else
	{
		temp=p->link;
		p->link=temp->link;
		free(temp);
	}
}

void countnodes(struct node *head)
{
	int n=0;
	struct node *p;
	p=head;
	while(p!=NULL)
	{
		n++;
		p=p->link;
	}
	printf("No of nodes in the list are: %d \n",n-1);

}



void insertbefore(struct node *head,int data,int x)
{
	struct node *temp,*p;

	p=head;
	while(p->link!=NULL)
	{
		if(p->link->info==x)
			break;
		p=p->link;
	}
	if(p->link==NULL)
		printf("%d not present in list \n",x);
	else
	{
		temp=(struct node * )malloc(sizeof(struct node));
		temp->info=data;
		temp->link=p->link;
		p->link=temp;

	}
}











