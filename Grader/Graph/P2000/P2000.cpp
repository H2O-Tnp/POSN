#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
const int INF = INT_MAX;

//          node w
vector<pair<int,int>> adj[MAX_N];
int max_dis[MAX_N];

int main(){
    for(auto& i:max_dis){
        i=INF;
    }
    int n,m,q;
    cin>>n>>m>>q;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    while(q--){
        int u,v,k;
        cin>>u>>v>>k;
        // cout<<"test\n";
        //                  w   node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.emplace(0,u);
        max_dis[u]=0;
        while(!pq.empty()){
            auto [cur_dis,cur_node] = pq.top();
            pq.pop();
            if(cur_dis > max_dis[cur_node]) continue;
            // cout<<"Cur: "<<cur_node<<endl;
            for(auto [adj_node,adj_dis]:adj[cur_node]){
                // cout<<"curdis: "<<cur_dis<<" adjdis: "<<adj_dis<<" min: "<<min_dis[adj_node]<<endl;
                if(cur_dis + adj_dis < max_dis[adj_node]){
                    max_dis[adj_node]=cur_dis + adj_dis;
                    if(adj_node == v){
                        cout<<"=\n";
                        continue;
                    }
                    pq.emplace(max_dis[adj_node],adj_node);
                }
            }
        }
        for(int i=0;i<=v;i++){
            cout<<max_dis[i]<<' ';
        }cout<<endl;

        // 
        bool cango = true;
        for(int i=u;i<=v;i++){
            cout<<max_dis[i]<<' '<<k<<endl;
            if(k>max_dis[i]){
                cout<<"No\n";
                cango = false;
                break;
            }
        }
        if(!cango){
            continue;
        }
        cout<<"Yes\n";
    }

}