#include<bits/stdc++.h>
using namespace std;

set<char>FOLLOW[1000];
vector<string> G[1000];
set<char>FIRST[1000];
    bool vis[1000];

void F(int start){

    if(vis[start])return;

    for(int i=0;i<G[start].size();i++){
        if(G[start][i]=="~"){
            FIRST[start].insert('~');
        }
        else if(!isupper(G[start][i][0])){
            FIRST[start].insert(G[start][i][0]);
        }
        else{
                bool flag;
                int k;
            for(k=0;k<G[start][i].length();k++){
            char nxt=G[start][i][k];
            if(!isupper(nxt)){
                  FIRST[start].insert(nxt);
                  break;
            }

            if(!vis[nxt-'A'])
                F(nxt-'A');

                flag=0;
            for(set<char>::iterator itr=FIRST[nxt-'A'].begin();itr!=FIRST[nxt-'A'].end();itr++){
                if((*itr)=='~'){
                    flag=1;
                }
                else FIRST[start].insert(*itr);
            }
                if(!flag) break;
            }
            if(k==G[start][i].length()){
                FIRST[start].insert('~');
            }
        }
    }
    vis[start]=1;
}

void Follow(int start)
{
    if(start==0){
        FOLLOW[start].insert('$');
    }

    for(int i=0;i<G[start].size();i++){
            int j;
        for( j=0;j<G[start][i].size()-1;j++){
            char ch=G[start][i][j];
            if(isupper(ch)){
                bool f=false;
                int k;
                for(k=j+1;k<G[start][i].size();k++){
                char nx=G[start][i][k];
                if(!isupper(nx)){
                    FOLLOW[ch-'A'].insert(nx);
                    break;
                }
                else{
                        f=false;
                    for(set<char>::iterator itr=FIRST[nx-'A'].begin();itr!=FIRST[nx-'A'].end();itr++){
                        if((*itr)=='~'){
                            f=true;
                        }
                        else FOLLOW[ch-'A'].insert(*itr);
                    }
                    if(!f)break;
                }
                }
                if(k==G[start][i].size()){
                    for(set<char>::iterator itr=FOLLOW[start].begin();itr!=FOLLOW[start].end();itr++){
                        FOLLOW[ch-'A'].insert(*itr);
                    }
                }
            }
        }

        char ch=G[start][i][j];
        if(isupper(ch)){
            for(set<char>::iterator itr=FOLLOW[start].begin();itr!=FOLLOW[start].end();itr++){
                FOLLOW[ch-'A'].insert(*itr);
            }
        }
    }
}
int main()
{
    int test=0,t=0,i,j,k,n,m;
    string str;

    fstream fin,fout;
    fin.open("input.txt");
    fout.open("output.txt");
    cout<<"\nEnter the number of grammars: ";
    fin>>test;
    cout<<test<<"\n";

    while(t++ != test){
            for(i=0;i<1000;i++){
                G[i].clear();
                FIRST[i].clear();
                FOLLOW[i].clear();
            }
            memset(vis,0,sizeof(vis));
    cout<<"\n\nEnter number of nonterminals: ";
    fin>>n;
    cout<<n<<"\n";
    for(i=0;i<n;i++){
        cout<<"\nEnter the productions for NT "<<(char)(i+'A')<<": ";
        fin>>m;
        cout<<m<<" ";
        for(j=0;j<m;j++){
            fin>>str;
            cout<<str<<" ";
            G[i].push_back(str);
        }

    }
    for(i=0;i<n;i++){
        F(i);
    }
    fout<<"\n"<<t<<")\nFIRST TABLE: \n";
    cout<<"\n"<<t<<")\nFIRST TABLE: \n";
    for(i=0;i<n;i++){
            fout<<'\t'<<char(i+'A')<<"-> ";
            cout<<'\t'<<char(i+'A')<<"-> ";
            for(set<char>::iterator itr=FIRST[i].begin();itr!=FIRST[i].end();itr++){
                fout<<(*itr)<<" ";
                cout<<(*itr)<<" ";
            }
        fout<<"\n";
        cout<<"\n";
    }
    for(i=0;i<n;i++){
        Follow(i);
    }
    for(i=0;i<n;i++){
        Follow(i);
    }
    fout<<"FOLLOW TABLE: \n";
    cout<<"FOLLOW TABLE: \n";
    for(i=0;i<n;i++){
            fout<<'\t'<<char(i+'A')<<"-> ";
            cout<<'\t'<<char(i+'A')<<"-> ";
            for(set<char>::iterator itr=FOLLOW[i].begin();itr!=FOLLOW[i].end();itr++){
                fout<<(*itr)<<" ";
                cout<<(*itr)<<" ";
            }
            fout<<"\n";
            cout<<"\n";
    }
    }
}

