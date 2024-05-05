#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
vector<pair<int,int>> adj[MAXN];
bool nb[MAXN];
bool visited[MAXN];
int dis[MAXN];

int maxd;

void dfs(int u) {
    for (auto [v,w] : adj[u]) {
        if(visited[v]) continue;
        visited[v] = true;
        dis[v] = w + dis[u];
        // ! neighbor
        if(!nb[v]){
            dfs(v);
        } else {
            maxd = max(maxd,dis[v]);
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i< N  ;i++){
        cin>>nb[i];
    }
    for(int i=0;i< N-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    // query
    while(Q--){
        int X; cin>>X;
        if(nb[X]){
            cout<<0<<"\n";
            continue;
        }
        for(int i=0;i< N;i++){
            dis[i] = INT_MIN;
            visited[i] = false;
        }
        maxd=INT_MIN;
        dis[X] = 0;
        visited[X] = true;
        dfs(X);
        cout<<maxd<<"\n";
    }
}