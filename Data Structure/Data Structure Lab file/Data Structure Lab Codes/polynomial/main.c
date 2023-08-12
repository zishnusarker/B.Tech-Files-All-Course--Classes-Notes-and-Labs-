#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
   int expr ;
   struct node*next;
};
struct node*Getnode(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}

void Insbeg(struct node **list,int c, int e){
    struct node *temp;
    temp=Getnode();
    temp->coef=c;
    temp->expr=e;
    temp->next=*list;
    *list=temp;
}

 void Inend(struct node **list,int c,int e){
   struct node *temp,*p;
   temp= *list;
   if(*list==NULL)
      Insbeg(&(*list),c,e);
    else
    {
        while(temp->next!=NULL)
           temp=temp->next;
        p=Getnode();
        p->coef=c;
        p->expr=e;
        p->next=NULL;
        temp->next=p;
    }

}

 void Traverse(struct node *list)
{
    struct node *t;
    t=list;
    while(t!=NULL){
        printf("\t %dX%d +",t->coef,t->expr);
        t=t->next;
    }
}

struct node * addPolynomial(struct node *poly1,struct node *poly2){
    struct node *poly3=NULL;
    struct node *p,*q;
    p=poly1;
    q=poly2;

    while(p!=NULL && q!=NULL){
        if(p->expr==q->expr){
            Inend(&poly3,p->coef+q->coef,p->expr);
            p=p->next;
            q=q->next;
        }
        else{
            if(p->expr>q->expr)
            {
                Inend(&poly3,p->coef,p->expr);
                p=p->next;
            }
            else
            {
               Inend(&poly3,q->coef,q->expr);
                q=q->next;
            }
        }
    }
    while(p!=NULL){
         Inend(&poly3,p->coef,p->expr);
                p=p->next;
    }

     while(q!=NULL){
         Inend(&poly3,q->coef,q->expr);
                q=q->next;
    }

    return poly3;
}

int  main() {
    struct node *start1,*start2,*start3;
    start1=NULL;
    start2=NULL;
    start3=NULL;


    int x;

    Inend(&start1,3,8);
    Inend(&start1,5,7);
    Inend(&start1,2,6);
    Inend(&start1,8,4);
    printf("\n First Polynomial is:= ");
    Traverse(start1);

    Inend(&start2,4,8);
    Inend(&start2,5,6);
    Inend(&start2,7,2);
    Inend(&start2,3,0);
    printf("\n Second Polynomial is:= ");
    Traverse(start2);

    start3=addPolynomial(start1,start2);
    printf("\n\n");
    printf("The addition is :- ");
    Traverse(start3);

     return 0;
}
