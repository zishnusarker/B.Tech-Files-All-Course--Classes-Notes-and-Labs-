#include <bits/stdc++.h>
using namespace std;

string check="b+cd$";
int m=0;

void M();
void N();
void O();

int main(){
	M();
	if(check[m]=='$')
		cout<<"recursive descent parser";
	else
		cout<<"not a recursive descent parser";
	return 0;
}

void M(){
	if(check[m]!='a')
		return;
	m++;
	N();
}

void N(){
	if(check[m]!='+')
		return;
	m++;
	O();
	N();
	
}

void O(){
	M();
}