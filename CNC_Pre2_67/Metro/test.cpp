#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N=1e5+5;
vector<pair<int,int>> adj[MAX_N];
int min_dis[MAX_N];
bool visited[MAX_N];
 
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int k,x;
        scanf("%d %d",&k,&x);
        int u;
        scanf("%d",&u);
        for(int j=1;j<k;j++){
            int v;
            scanf("%d",&v);
            adj[u].emplace_back(v,x);
            adj[v].emplace_back(u,x);
            u=v;
        }
    }
    for(int i=0;i<MAX_N;i++){
        min_dis[i]=INT_MAX;
    }
    priority_queue<pair<int,int>> pq;
    pq.emplace(0,0);
    min_dis[0]=0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if (visited[u]){
			continue;
		}
        visited[u]=true;
 
        for(auto [v,w] : adj[u]){
            if(!visited[v] and w + min_dis[u] < min_dis[v]){
                min_dis[v] = w+min_dis[u];
                pq.emplace(-min_dis[v],v);
            }
        }
    }
    if (visited[n-1] == false){
		min_dis[n-1]=-1;
	}else {
		cout<<min_dis[n-1];
	}
}