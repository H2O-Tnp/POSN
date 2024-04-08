#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
const int INF = 1e9+7;
vector<pair<int,int>> adj[MAX_N];
bool visited[2][MAX_N];
int dis[2][MAX_N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    for(int i=0;i<=1;i++)
        for(int j=0;j<=n;j++)
            dis[i][j]=INF;
                     //   w  cop node
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    pq.emplace(0,0,1);
    dis[0][1] = 0;

    while(!pq.empty()){
        auto [lw,cop,u] = pq.top();
        pq.pop();
        if(visited[cop][u]) continue;
        visited[cop][u] = true;
        // cout<<u<<endl;
        for(auto [v,w] : adj[u]){
            // normal
            if(w+dis[cop][u] < dis[cop][v]){
                dis[cop][v] = w+dis[cop][u];
                pq.emplace(dis[cop][v],cop,v);
            }
            // specific (add cop)
            if(cop == 0 and k + dis[0][u] < dis[1][v]){
                dis[1][v] = k + dis[0][u];
                pq.emplace(dis[1][v],1,v);
            }
        }
    }
    int ans = min(dis[0][n],dis[1][n]);

    if(ans <= t){
        cout<<"Happy Winnie the Pooh :3\n";
        cout<<ans;
    }
    else{
        cout<<"No Honey TT";
    }
}
/*
4 5 1 2
1 2 2
2 3 3
1 3 5
1 4 4
3 4 3
*/

/*
7 7 2 6
1 2 1
2 3 1
3 4 1
4 7 3
2 5 1
5 6 1
4 6 1
*/