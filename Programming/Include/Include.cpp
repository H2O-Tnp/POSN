#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000+5;
vector<int> adj[MAX_N];
bool visited[MAX_N];
bool err=false;

void dfs(int u){
    visited[u]=true;
    // if(adj[u].empty()){
    //     cout<<"test\n";
    //     return;
    // }
    for(auto adjV:adj[u]){
        if(!visited[adjV]){
            dfs(adjV);
        }
        else{
            err=true;
        }
    }
}

void clearVis(int n){
    err = false;
    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int in;
            cin>>in;
            adj[i].push_back(in);
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].empty()){
            cout<<"NO\n";
            continue;
        }
        clearVis(n);
        dfs(i);
        if(err) cout<<"YES\n";
        else cout<<"NO\n";
    }
}