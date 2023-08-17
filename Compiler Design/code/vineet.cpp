#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Name: Zishnendu Sarker ";
        cout<<"Roll : 2K19/CO/450";
	cout<<"Enter the Grammer \n";
	string grammer;
	cin>>grammer;
	cout<<"The grammer which is given "<<grammer;
	char lhs;
	lhs=grammer[0];
	vector<string> rhs;
	for(int i=3;i<grammer.size();)
	{
		int j=i;
		while(grammer[j]!='|' && grammer[j]!='\0')
		{
		   j++;
		}
		rhs.push_back(grammer.substr(i,j-i));
		i=j+1;
	}

		
	
	vector<string> a;
	vector<string> b;
	for(int i=0;i<rhs.size();i++)
	{
		if(rhs[i][0]==lhs)
		{
			a.push_back(rhs[i].substr(1));
		}
		else{
			b.push_back(rhs[i]);
		}
	}
	cout<<"/n"<<lhs<<"->";
	for(int i=0;i<b.size();i++)
	{
		cout<<b[i]<<lhs<<"1"<<"|";
		
	}
	cout<<"\n"<<lhs<<"1"<<"->";
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i]<<lhs<<1<<"|";
	}
	return 0;
}
