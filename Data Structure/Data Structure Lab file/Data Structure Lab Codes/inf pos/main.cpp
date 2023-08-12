#include<iostream>
#define MAXSIZE 20
using namespace std;
struct stack
{
    int top;
    int arr[MAXSIZE];
}s;


void push(struct stack *s, int a)
{
    if (s->top == MAXSIZE - 1)
    {
        cout<<"STACK IS ALREADY FULL";
    }
	else
    {
        s->top++;
        s->arr[s->top] = a;
    }
}

void pop(struct stack *s)
{
    int val;
    if (s->top == -1)
    {
        cout<<"STACK IS ALREADY EMPTY";
        val = -1;
    }
    else
    {
        val = s->arr[s->top];
        s->top--;
    }
   // return val;
}

bool isoperator(char c)
{
    if(c=='+'||c=='-'||c=='/'||c=='*'||c=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int precedence(char c)
{
    if(c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return -1;
}
string infix_to_postfix(struct stack s,string a)
{
    string postfix;

    for(int i=0;i<a.length();i++)
    {
        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
        {
            postfix+=a[i];
        }
        else if(a[i]=='(')
        {
            push(&s,a[i]);
        }
        else if(a[i]==')')
        {
            while((s.arr[s.top]!='(')&&(s.top!=-1))
            {
                char temp=s.arr[s.top];
                postfix+=temp;
                pop(&s);
            }
            if(s.arr[s.top]=='(')
            {
                pop(&s);
            }
        }
        else if(isoperator(a[i]))
        {
            if(s.top==-1)
            {
                push(&s,a[i]);
            }
            else
            {
                if(precedence(a[i]>precedence(s.arr[s.top])))
                {
                    push(&s,a[i]);
                }
                else if(precedence(a[i])==precedence(s.arr[s.top])&&(a[i]=='^'))
                {
                    push(&s,a[i]);

                }
                else
                {
                    while((s.top!=-1)&&(precedence(a[i])<=precedence(s.arr[s.top])))
                    {

                        postfix+=s.arr[s.top];
                        pop(&s);
                    }
                    push(&s,a[i]);
                }

            }
        }
    }
    while(s.top!=-1)
    {
        postfix+=s.arr[s.top];
        pop(&s);
    }
    return postfix;
}

int main()
{
    s.top=-1;
    string infix_exp,postfix_exp;

    cout<<"\nEnter a Infix Expresssion : ";
    cin>>infix_exp;
    cout<<"\n\n Infix Expression : "<<infix_exp;
    postfix_exp=infix_to_postfix(s,infix_exp);

    cout<<"\n\nPostfix Expression : "<<postfix_exp;
    cout<<endl;

    return 0;

}
