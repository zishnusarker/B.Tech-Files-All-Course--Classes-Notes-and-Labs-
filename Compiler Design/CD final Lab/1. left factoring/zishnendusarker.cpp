#include<bits/stdc++.h>
using namespace std;
int main ()
{
     char a[10], al [10], a2 [10], a3[10], a4[10],a5[10];
     21nti ,j=0,k,l;
     cout<<"Enter any productions A->");
     cin>>a;
     for (i=0;a[i]!=' |';i++,j++)
          al[j]=a[i];
     al [j]=' \0';
     for (j=++i, i=0;a[j]!=' \0' ;j++,i++)
          a2 [i]=a[j];
     a2 [i]=' \0';
     k=0;1=0;
     for (i=0;i<strlen (al) ||i<strlen (a2);i++)
     {
          if (al [i]==a2 [i])
                a3 [k++]=al [i];
          else
           {
                a4[1]=al [i];
                a5 [1]=a2 [i];
                1++;
           }
     }
     a3 [k] ='X';a3[++k] =' \O';
    a4 [1]=' |'; a5[1]=' \0';
     a4 [++1]=' \0';
     strcat (a4,a5);
     cout<<"\n A->"<<a3;
     cout<<"\n X->"<<a4;
     return 0;