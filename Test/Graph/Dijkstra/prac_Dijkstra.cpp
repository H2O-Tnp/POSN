#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
const int INF = 1e9;

vector<pair<int, int>> adj[MAX_N];
int min_dis[MAX_N];
int par[MAX_N];


void addEdge(int u,int v,int w){
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

int main(){
    int n,m,start;
    // cin>>n>>m>>start;
    n=9;
    start=0;
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);


    for(int i=0;i<n;i++){
        par[i]=i;
    }
    // while(m--){
    //     int u,v,w;
    //     cin>>u>>v>>w;
    //     adj[u].emplace_back(v, w);
    //     adj[v].emplace_back(u, w);
    // }
    // INF all dis
    for(int i=1-1;i<=n-1;i++){
        min_dis[i]=INF;
    }

    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    pq.emplace(0,start);
    min_dis[start] = 0; // !!!
    
    while(!pq.empty()){
        auto [cur_dis, ver] = pq.top();
        pq.pop();

        if(cur_dis > min_dis[ver]){
            continue;
        }
        for(auto [adj_ver, adj_w] : adj[ver]){
            if(cur_dis+adj_w < min_dis[adj_ver]){
                min_dis[adj_ver] = cur_dis+adj_w;
                pq.emplace(min_dis[adj_ver],adj_ver);
                par[adj_ver] = ver;
            }
        }
    }

    int v=8; // end !!!
    if (min_dis[7] == 1e9){
        cout<<"-1 ";
        return 0;
    }

    vector<int> path;
    while(par[v]!=v){
        path.push_back(v);
        v = par[v];
    }
    path.push_back(0);
    reverse(path.begin(),path.end());

    for(auto i:path){
        cout<<i<<' ';
    }cout<<endl;

    // for(int i=1-1;i<=n-1;i++){
    //     if(min_dis[i]==INF) cout<<"-1\n";
    //     else cout<<min_dis[i]<<endl;
    // }
}