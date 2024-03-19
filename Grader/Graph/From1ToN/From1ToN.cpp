#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 101;
const int INF = 1e9;

vector<pair<int,int>> adj[MAX_N];
int min_dis[MAX_N];
int par[MAX_N];

int main(){
    int n,m;
    cin>>n>>m;
    int last = n;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    for(int i=1;i<=n;i++){
        min_dis[i]=INF;
    }
    // every vertice is it own parent
    // !!!
    for(int i=1;i<=n;i++){
        par[i]=i;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.emplace(0,1);
    min_dis[1] = 0;

    while(!pq.empty()){
        auto top = pq.top();
        auto cur_dis = top.first;
        auto cur_ver = top.second;

        if(cur_dis < min_dis[cur_ver]) continue;
        pq.pop();
        for(auto i:adj[cur_ver]){
            auto adj_ver = i.first;
            auto adj_w = i.second;
            if(cur_dis + adj_w < min_dis[adj_ver]){
                min_dis[adj_ver] = cur_dis + adj_w;
                pq.emplace(min_dis[adj_ver], adj_ver);
                // parent of [adj_vertice] = current_vertice
                par[adj_ver] = cur_ver;
            }
        }
    }

    // last vertice have no min distance
    if(min_dis[last]==INF){
        cout<<"-1";
    } else {
        // !!!
        int v=last;
        vector<int> res;
        while(par[v]!=v){
            res.push_back(v);
            // back track to parent until head(start vertice)
            v = par[v];
        }
        res.push_back(1);
        // !!!
        reverse(res.begin(),res.end());

        for(auto i:res){
            cout<<i<<' ';
        }
    }
}