#include <bits/stdc++.h>
using namespace std;
int r,c;
int find_val(int a){
	int mod = a%3;
	int val;
	if(mod==0 || mod==1 )		val = (a/3)*2;		 	
	else val = 1 + (a/3)*2;
	return val;
}
int process(){
	int ans = 0;
	int val_r = find_val(r);
	int val_c = find_val(c);
	if(r*c==1)	ans = 0;
	else if(r==1)	ans = val_c;
	else if(c==1)	ans = val_r;
	else ans = val_r*c + (r-val_r)*val_c; 
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>r>>c){
    	cout<<process()<<"\n";
    }
	return 0;
}
