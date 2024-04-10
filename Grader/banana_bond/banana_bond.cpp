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
bool invert = false;

int find_root(int u){
    if(u==parent[u]) return u;
    return parent[u]=find_root(parent[u]);
}

bool merge(int a,int b){
    int u=find_root(a), v=find_root(b);
    if(u==v) return false;
    parent[v] = u;
    return true;
}

int countComp(){
    // for(int i=1;i<=V;i++){
    //    visited[i] = false; 
    // }

    
    
    return comp;
}

int main(){
    
    cin>>V>>E>>Q;
    int comp = V;
    // vector<int> max_e;
    // setup
    for(int i=1;i<=E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w,i);
        adj[v].emplace_back(u,w,i);
        if (merge(u, v) == true) comp--;
        eid[i]=true;
        pq.emplace(w,v,i);
        // pq.emplace(w,u,i);
        // max_e.emplace_back(w);
    }

    // main process
    while(!pq.empty()){
        auto [max_w,max_v,id] = pq.top();
        pq.pop();
        // cout<<max_v<<' '<<max_w<<' '<<id<<"\n";
        eid[id] = false;
        // cout<<"finding\n";
        int n_com = countComp();
        // cout<<"numof components : "<<n_com<<"\n";
        ans[n_com]=max_w;
    }
    for(int i=0;i<Q;i++){
        int q;
        cin>>q;
        
        cout<<ans[q]<<"\n";
    }
}

/*
7 7 6
1 2 1
1 6 7
2 5 6
2 3 2
2 4 3
6 7 6
6 5 6
2
7
4
5
6
3


6 7 3

*/