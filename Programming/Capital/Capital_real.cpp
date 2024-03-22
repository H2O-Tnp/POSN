#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000+5;
//          ver weight
vector<pair<int,int>> adj[MAX_N];
int sum_dis[MAX_N];
int max_dis=-1;

void dfs(int cur_v){
    for(auto [adj_V,adj_dis] : adj[cur_v]){
        sum_dis[adj_V] = sum_dis[cur_v] + adj_dis;
        dfs(adj_V);
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
    }
    dfs(1);

    for(int i=1;i<=n;i++){
        max_dis = max(sum_dis[i],max_dis);
    }
    cout<<max_dis;
}