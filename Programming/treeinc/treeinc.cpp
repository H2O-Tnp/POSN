#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300005;
vector<int> adj[MAX_N];
int dis[MAX_N];
int max_dis=0;

void dfs(int u){
    dis[u]=1;
    for(auto adj_v:adj[u]){
        if(dis[adj_v]==-1){ // not visit
            dfs(adj_v);
        }
        dis[u] = max(dis[u],dis[adj_v]+1);
        // cout<<u<<" > "<<adj_v<<" max_dis: "<<dis[u]<<endl;
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[min(u,v)].push_back(max(u,v));
        dis[i]=-1;
    }
    dis[n]=-1;
    for(int i=1;i<=n;i++){
        if(dis[i]!=-1) continue;
        dfs(i);
        max_dis = max(dis[i],max_dis);
    }
    cout<<max_dis;
}