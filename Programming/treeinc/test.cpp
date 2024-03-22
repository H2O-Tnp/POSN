#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 300005;
vector<int> adj[MAX_N];
int max_dis = 0;
bool visited[MAX_N];


void dfs(int u,int cnt){
    visited[u]=true;
    cnt++;
    for(auto adj_v:adj[u]){
            // cout<<adj_v<<" > "<<u<<" cnt: "<<cnt<<endl;
        if(!visited[adj_v]){
            dfs(adj_v, cnt);
        }
    }
    if(cnt>max_dis) max_dis=cnt;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        
        adj[min(u,v)].push_back(max(u,v));
        // adj[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i, cnt);
        }
    }
    cout<<max_dis;
}

/*
9
1 2
2 9
1 7
6 8
2 6
3 9
4 9
5 4
*/