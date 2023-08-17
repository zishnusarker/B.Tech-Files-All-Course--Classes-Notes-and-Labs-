#include <bits/stdc++.h>
using namespace std;

bool check=false; 
int ind = 0;
void first(unordered_map<char,vector<string>> mp,char NT,unordered_set<char>& ff){
    
    vector<string> rhs=mp[NT];
    
    for(int i=0;i<rhs.size();i++)
    {
        if(islower(rhs[i][0])||rhs[i][0]=='+'||rhs[i][0]=='('||rhs[i][0]==')'||rhs[i][0]==','||rhs[i][0]=='*'||rhs[i][0]=='/'||rhs[i][0]=='-'){
        ff.insert(rhs[i][0]);
    }
        

    else if(rhs[i][0]=='e'){
        ff.insert('e');
    }

    else{
        while(ind<rhs[i].size()){
            if(isupper(rhs[i][ind])||rhs[i][0]!='+'||rhs[i][0]!='('||rhs[i][0]!=')'||rhs[i][0]!=','||rhs[i][0]!='*'||rhs[i][0]!='/'||rhs[i][0]!='-'){
                first(mp,rhs[i][ind++],ff);
            }
            else{
                ff.insert(rhs[i][ind]);
                break;
            }
        }
        
    }
    }
        
}

int main(){
    cout<<"Please enter the total number of production : ";
    int n;
    cin>>n;
    unordered_map<char,vector<string>> mp;
    for(int i=1;i<=n;i++){
        cout<<"Give me lhs of production "<<i<<": ";
        char lhs;
        cin>>lhs;
        cout<<"Enter rhs production "<<i<<": ";
        string rhs;
        cin>>rhs;
        mp[lhs].push_back(rhs);
    }
    cout<<"The Productions are: \n";
    for(auto it:mp){
        cout<<it.first<<"->";
        for(int i=0;i<it.second.size();i++){
            cout<<it.second[i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Firsts: \n";
    for(auto it:mp){
        char NT=it.first;
        unordered_set<char> ff;
        first(mp,NT,ff);
        cout<<"First of "<<NT<<"="<<"{ ";
        for(auto it:ff){
            cout<<it<<" ";
        }
        cout<<"}"<<endl;
    }

    return 0;
}

