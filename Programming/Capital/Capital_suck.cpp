#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000+5;
//          ver weight
vector<pair<int,int>> adj[MAX_N];
vector<int> min_dis(MAX_N,INT_MAX);

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    //                weight ver 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.emplace(0,1);
    min_dis[1]=0;
    while(!pq.empty()){
        auto [cur_dis,cur_v] = pq.top();
        pq.pop();
        for(auto [adj_ver,adj_w] : adj[cur_v]){
            if(cur_dis + adj_w < min_dis[adj_ver]){
                min_dis[adj_ver] = cur_dis + adj_w;
                pq.emplace(min_dis[adj_ver],adj_ver);
            }
        }
    }
    int res=-1;
    for(int i=1;i<=n;i++){
        res = max(min_dis[i],res);
    }
    cout<<res;
}