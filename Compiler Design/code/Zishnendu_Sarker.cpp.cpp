 /*
E->iE'
E'->+iE'/e;
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void EE(int& l,string c){
    if(c[l]!='+')
        return;
    l++;
    if(c[l]!='i')
        return;
    l++;
    EE(l,c);
}
void E(int& l, string c){
    if(c[l]!='i')
        return;
    l++;
    EE(l,c);
}
int main()
{
    string c="i+i$";
    int l=0;
    E(l,c);
    if(c[l]=='$')
        cout<<"It is accepted by this grammar";
    else
        cout<<"It is not accepted by this grammar";
    return 0;
}
