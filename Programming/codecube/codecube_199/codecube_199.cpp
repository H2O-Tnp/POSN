#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
vector<pair<int,int>> adj[MAX_N];
int max_dis[MAX_N];
bool visited[MAX_N];


int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);

    }
    int t;
    cin>>t;

    priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
    vector<int> order;
    for(int i=0;i<=n;i++){
        max_dis[i]=-1;
    }
    pq.emplace(0,1);
    int totaldis=0;
    while(!pq.empty()){
        auto [w,u] = pq.top();
        pq.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        order.push_back(u);
        totaldis+=w;
        // cout<<u<<" "<<w<<endl;
        for(auto [v,adjw] : adj[u]){
            pq.emplace(adjw, v);
            
        }
    }
    sort(order.begin(),order.end());
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<-1;
            return 0;
        }
    }
    cout<<totaldis<<endl;
    if(t==2){
        for(auto i:order){
            cout<<i<<' ';
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<max_dis[i]<<' ';
    // }
    // cout<<pq.top().first;
}