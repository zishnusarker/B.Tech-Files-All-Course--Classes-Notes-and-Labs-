#include <iostream>
#include <string>
using namespace std;

int main(){
    char c; 
    int n;
    cout<<"Enter the Non-Terminal :";
    cin>>c;
    cout<<"Enter the Number of Productions :";
    cin>>n;
    string arr[n];
    string common="";
    for(int i=0;i<n;i++){
        cout<<"Enter the production "<<i+1<<":";
        cin>>arr[i];
    }
    cout<<"The Entered Grammer is :"<<c<<" -> ";
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<"| ";
    }
    cout<<arr[n-1]<<endl;
    
    for(int i=0;i<arr[0].size();i++){
        bool check=true;
        for(int j=1;j<n;j++){
            if(arr[j][i]!=arr[0][i])
                check=false;
                break;
        }
        if(check==true) common+=arr[0][i];
    }
    int s=common.size();
    for(int i=0;i<n;i++){
        arr[i].erase(0,s);
        if(arr[i]=="")
            arr[i]="e";
    }
    cout<<"\nAfter Left Factoring :"<<endl;
    cout<<c<<" -> "<<common<<c<<"'"<<endl;
    cout<<c<<"' -> ";
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<"| ";
    }
    cout<<arr[n-1];
}