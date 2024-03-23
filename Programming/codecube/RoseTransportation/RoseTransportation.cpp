#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e5+5;
vector<pair<int,int>> adj[MAX_N];
//                   w  node
priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
bool visited[MAX_N];
int t[MAX_N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    while(m--){
        int u,v;
        cin>>u>>v;
        int cost = t[u]+t[v];
        adj[u].emplace_back(v,cost);
        adj[v].emplace_back(u,cost);
    }
    pq.emplace(0,1);
    int res=0;
    while(!pq.empty()){
        auto [w,u] = pq.top();
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        res+=w;
        for(auto [v,adjw] : adj[u]){
            if(!visited[v]){
                pq.emplace(adjw,v);
            }
        }
    }
    cout<<res;
}

/*
3 3
1 2 3
1 2
2 3
1 3
*/