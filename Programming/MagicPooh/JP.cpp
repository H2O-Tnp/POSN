// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define T tuple<int,int,int>
using namespace std;

int n,m,k,t;

int dist[2][100007];

int ans=INT_MAX;
vector<pair<int,int>> adj[100007];
priority_queue<T,vector<T>,greater<T>> q;

bool visited[2][100007];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k>>t;
    // cin
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(w,v);
        adj[v].emplace_back(w,u);
    }
    // Fill
    for(int i=0;i<=1;i++)
        for(int j=0;j<=n;j++)
            dist[i][j]=INT_MAX;
    
    dist[0][1]=0;
    //   dist cop node;
    q.emplace(0,0,1);
    while(!q.empty()){
        auto [dis,cop,u]=q.top();
        q.pop();
        if(visited[cop][u]) continue;
        visited[cop][u]=true;
        for(auto [w,v]:adj[u]){
            if(cop==1)
            {
                if(dist[cop][u]+w<dist[cop][v]){
                    dist[cop][v]=dist[cop][u]+w;
                    q.emplace(dist[cop][v],cop,v);
                }
            }
            else if(cop==0)
            {
                if(dist[cop][u]+w < dist[cop][v]){
                    dist[cop][v]=dist[cop][u]+w;
                    q.emplace(dist[cop][v],cop,v);
                }
                if(dist[cop][u]+k < dist[cop+1][v]){
                    dist[cop+1][v]=dist[cop][u]+k;
                    q.emplace(dist[cop+1][v],cop+1,v);
                }
            }
        }
    }
    ans=min(dist[1][n],dist[0][n]);
    if(ans<=t)
    {
        cout<<"Happy Winnie the Pooh :3\n";
        cout<<ans;
    }
    else
    {
        cout<<"No Honey TT";
    }
}