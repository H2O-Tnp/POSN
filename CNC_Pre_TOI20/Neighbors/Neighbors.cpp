#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
vector<pair<int,int>> adj[MAXN];
bool nb[MAXN];
bool visited[MAXN];
int dis[MAXN];

// vector<int> nb_check;

int main(){
    int N,Q;
    cin>>N>>Q;
    for(int i=1;i<= N;i++){
        cin>>nb[i];
    }
    for(int i=1;i<  N;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    // query
    while(Q--){
        int X; cin>>X;
        //dijkstra
        //                   w  node
        for(int i=1;i<= N;i++){
            dis[i] = INT_MAX;
            visited[i] = false;
        }
        cout<<"test\n";
        priority_queue<pair<int,int>> pq;
        pq.emplace(0,X);
        dis[X] = 0;
        while(!pq.empty()){
            auto [uw,u] = pq.top();
            if(visited[u]) continue;
            visited[u] = true;

            for(auto [vw,v] : adj[u]){
                if(vw + dis[u] > dis[v]){
                    dis[v] = vw + dis[u];
                    if(!nb[u]){
                        pq.emplace(dis[v],v);
                    }
                }
            }
        }
    }
}