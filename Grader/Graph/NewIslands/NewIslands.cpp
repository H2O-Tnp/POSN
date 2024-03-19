#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20];
bool visit[20];
vector<int> order;

bool found = false;

bool DFS(int u,int v){
    order.push_back(u);
    
    if(u==v){
        return true;
    }
    for(auto i:adj[u]){
        if(visit[i]==false){
            visit[i]=true;
            if(DFS(i,v)){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int st,en;
    cin>>st>>en;
    visit[st]=true;
    if(DFS(st,en)){
        cout<<"path:";
        for(auto i:order){
            cout<<i<<' ';
        }
    }
    else{
        cout<<"No path exists ("<<st<<" -> "<<en<<")";
    }
}
/*
7 11
0 3
1 0
1 2
1 4
2 7
3 4
3 5
4 3
4 6
5 6
6 7
0 7
*/