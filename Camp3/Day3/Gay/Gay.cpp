#include <bits/stdc++.h>
using namespace std;

vector<int> adj[4][100005];
int color[4][100005];
bool visited[4][100005];

bool dfs(int id,int u,int par,int c){
    // cout<<"u "<<u<<"\n";
    if(visited[id][u]){
        if(color[id][u]!=c){
            return false;
        }
        return true;
    }
    visited[id][u] = true;
    color[id][u] = c;

    for(auto v:adj[id][u]){
        if(v==par) continue;
        if(!dfs(id,v,u,3-c)){
            return false;
        }
        return true;
    }
}

int main(){
    int q;
    cin>>q;
    int id = 0;
    while(q--){ 
        int N,M;
        cin>>N>>M;
        for(int i=1;i<=M;i++){
            int a,b;
            cin>>a>>b;
            adj[id][a].emplace_back(b);
            adj[id][b].emplace_back(a);
        }
        
        if(!dfs(id, 0, 0, 1)){
            cout<<"Gay found!\n";
        }
        else{
            cout<<"Gay not found!\n";
        }
        
        for(int i=0;i<=N;i++){
            cout<<color[id][i]<<' ';
        }
        id++;
    }
}

/*
2
3 3
0 1
1 2
0 2

4 2
0 1
2 3

*/