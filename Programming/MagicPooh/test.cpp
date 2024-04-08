#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
const int INF = 1e9+7;
vector<pair<int,int>> adj[MAX_N];
bool visited[MAX_N];
int dis[MAX_N];

int main(){
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    fill(dis+1,dis+m+1,INF);
    // for(int i=1;i<=m;i++){
    //     cout<<dis[i]<<' ';
    // }
    // cout<<endl;
                    //   w   node
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.emplace(0,1);
    dis[1] = 0;
    //   par  w
    pair<int,int> par[n+1];
    par[1].first = 1;
    par[1].second = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        // cout<<u<<endl;
        for(auto [v,w] : adj[u]){
            if(w+dis[u] < dis[v] and !visited[v]){
                dis[v] = w + dis[u];
                pq.emplace(dis[v],v);
                // cout<<"v "<<v<<endl;
                par[v].first = u;
                par[v].second = w;
            }
        }
    }
    int p=n;
    // cout<<"test\n";
    if(dis[n]>t){
        int max_dis=-1;
        while(p!=1){
            max_dis=max(max_dis,par[p].second);
            // cout<<p<<' ';
            // cout<<':'<<par[p].second<<endl;
            p = par[p].first;
        }
        if(max_dis > k){
            dis[n] = dis[n] - max_dis + k;
            
        }

        if(dis[n] > t){
            cout<<"No Honey TT";
        }
        else{
            cout<<"Happy Winnie the Pooh :3\n";
            cout<<dis[n];
        }
        // cout<<endl;
        // cout<<"max "<<max_dis;
        // cout<<endl;
    }
    
    
    // for(int i=1;i<=n;i++){
    //     cout<<dis[i]<<' ';
    // }
}