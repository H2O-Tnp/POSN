#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
const int MAX_E = 2e5+5;
//          v   w
vector<tuple<int,int,int>> adj[MAX_N];
priority_queue<tuple<int,int,int>> pq;
bool eid[MAX_E];
bool visited[MAX_N];
//          n_com  w
unordered_map<int,int> ans(5e5+5);

int V,E,Q;

int countComp(){
    for(int i=1;i<=V;i++){
       visited[i] = false; 
    }
    int comp = 0;
    for(int i=1;i<=V;i++){
        if(visited[i]){
            continue;
        }
        comp++;
        queue<int> qu;
        qu.emplace(i);
        visited[i]=true;
        while(!qu.empty()){
            // cout<<"test\n";
            auto u = qu.front();
            qu.pop();
            for(auto[v,w,id]:adj[u]){
                if(eid[id]==false){
                    continue;
                }
                if(visited[v]){
                    continue;
                }
                visited[v]=true;
                qu.emplace(v);
            }
        }
    }
    return comp;
}

int main(){
    cin>>V>>E>>Q;
    // setup
    
    for(int i=1;i<=E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w,i);
        adj[v].emplace_back(u,w,i);
        eid[i]=true;
        pq.emplace(w,v,i);
    }

    // main process
    while(!pq.empty()){
        auto [max_w,max_v,id] = pq.top();
        pq.pop();
        eid[id] = false;
        int n_com = countComp();
        ans[n_com]=max_w;
    }
    for(int i=0;i<Q;i++){
        int q;
        cin>>q;
        cout<<ans[q]<<"\n";
    }
}