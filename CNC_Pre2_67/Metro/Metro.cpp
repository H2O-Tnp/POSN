#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+5;
vector<pair<int,int>> adj[MAX_N];
int min_dis[MAX_N];
bool visited[MAX_N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int k,x;
        cin>>k>>x;
        while(k--){
            int v;
            cin>>v;
            adj[v].emplace_back(n+i,x);
            adj[n+i].emplace_back(v,0);
        }
    }
    //n+m
    for(int i=0;i<m+n;i++){
        min_dis[i]=INT_MAX;
    }
    priority_queue<pair<int,int>> pq;
    pq.emplace(0,0);
    min_dis[0]=0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if (visited[u] == true) continue;
        visited[u]=true;
        // cout<<"vis: "<<u<<endl;
        for(auto [v,aw] : adj[u]){
            if(!visited[v] and aw+min_dis[u] < min_dis[v]){
                min_dis[v] = aw+min_dis[u];
                pq.emplace(-min_dis[v],v);
            }
        }
    }
    if (!visited[n-1]){
		cout<<-1;
	}else {
		cout<<min_dis[n-1];
	}
}

/*
7 4
4 12
0 1 2 4
3 2
0 3 5
4 6
1 6 3 4
2 5
6 3
*/
/*
2 3
2 5
0 1
2 4
1 0
2 20
0 1
*/