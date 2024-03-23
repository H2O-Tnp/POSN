#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adj[n+1];
    
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
    }
    int s;
    cin>>s;
    
    for(int i=0;i<n;i++){
        if(i==s) continue;
        // dijk
        int min_dis[n+5];
        int par[n+5];
        
        for(auto &it:min_dis){
            it=INT_MAX;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.emplace(0,s);
        min_dis[s]=0;
        par[s]=s;
        while(!pq.empty()){
            auto [w,u] = pq.top();
            pq.pop();
            if(w > min_dis[u]) continue;
            // cout<<"u "<<u<<endl;

            for(auto [v,adj_w] : adj[u]){
                if(adj_w + w < min_dis[v]){
                    min_dis[v] = adj_w + w;
                    pq.emplace(min_dis[v],v);
                    par[v]=u;
                }
            }
        }
        // print
        cout<<s<<" -> "<<i<<" (";
        if(min_dis[i]==INT_MAX){
            cout<<"inf)\n";
            continue;
        }
        else{
            cout<<min_dis[i]<<") ";
        }
        cout<<s<<' ';
        int temp=i;
        stack<int> order;
        while(par[temp]!=temp){
            order.push(temp);
            temp=par[temp];
        }
        while(!order.empty()){
            cout<<order.top()<<' ';
            order.pop();
        }
        cout<<endl;
    }
}