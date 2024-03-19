#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> adj[MAX_N]; // adjacency list for storing edges
bool visited[MAX_N]; // nodes should be visited once
long long sal[MAX_N];
int n;

void dfs(int u,long long bonus[]) {
    // add bonus to parent node
    sal[u] += bonus[u];

    // cout<<"DFS "<<u<<endl;
    // for(int i=1;i<=n;i++) cout<<"Node "<<i<<" Sal "<<sal[i]<<endl;

    for (auto v : adj[u]) {
        if (visited[v] == false) {
            visited[v] = true;
            // copy bonus from parent node to child
            sal[v] += sal[u];
            dfs(v,bonus);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    cin >> n >> m;
    for(int i=2;i<=n;i++){
        int par;
        cin>>par;
        adj[par].push_back(i);
    }

    long long K[n];
    fill(K,K+n+1,0);
    int u,in;
    for(int i=0;i<m;i++){
        cin >> u >> in;
        K[u] += in;
    }
    dfs(1,K);

    for(int i=1;i<=n;i++) cout<<sal[i]<<' ';
}