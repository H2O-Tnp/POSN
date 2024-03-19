#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> adj[30];
int min_dis[1000000];

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    for(int i=0;i<n;i++) min_dis[i] = INT16_MAX;
    // factory A : 0
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.emplace(0,0);
    min_dis[0]=0;

    while(!pq.empty()){
        auto cur_dis = pq.top().first;
        auto ver = pq.top().second;
        // auto[cur_dis,ver] = pq.top();
        pq.pop();
        if(cur_dis < min_dis[ver]) continue;
        // for(auto[adj_ver,adj_w]:adj[ver]){
        for(auto it=adj[ver].begin();it!=adj[ver].end();it++){
            auto adj_ver = (*it).first;
            auto adj_w = (*it).second;

            if(min_dis[ver]+adj_w < min_dis[adj_ver]){
                min_dis[adj_ver] = min_dis[ver]+adj_w;
                pq.emplace(min_dis[adj_ver],adj_ver);
            }
        }
    }
    for(int i=0;i<n;i++){
        char c = 'A'+i;
        cout<<c<<"->"<<min_dis[i]<<'\n';
    }
}

/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/