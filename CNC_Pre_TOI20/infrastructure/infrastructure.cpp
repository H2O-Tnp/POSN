#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
vector<int> vec(MAXN);
vector<int> adj[MAXN];
bool vis[MAXN];


long long ans = 0;

void dfs(int u,vector<int>& order){
    // cout<<"u "<<u<<"\n";
    for(auto v:adj[u]){
        if(vis[v]) continue;
        vis[v]= true;
        order.emplace_back(vec[v]);
        ans+=vec[v];
        // cout<<vec[v]<<"\n";
        dfs(v,order);
        // ans+=vec[v];
    }
}

int main(){
    int N,M,S,Q;
    cin>>N>>M>>S>>Q;

    for(int i=1;i<=N;i++){
        cin>>vec[i];
    }

    for(int i=1;i<=M;i++){
        int u,v; cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }


    while(Q--){
        int T; cin>>T;
        if(T==1){
            int X,Y;
            cin>>X>>Y;

            vector<int> order;
            for(int i=1;i<=N;i++){
                vis[i]=false;
            }
            vis[S] = true;

            ans = 0;
            dfs(S,order);

            int minnum=INT_MAX;
            for(int i=0;i<X;i++){
                if(order[i]<Y){
                    // cout<<"order "<<order[i]<<"\n";
                    minnum = min(minnum,order[i]);
                }
            }
            ans -= minnum;
            ans += Y;

            cout<<ans<<"\n";
        } else {
            int Y;
            cin>>Y;
        }
    }
}