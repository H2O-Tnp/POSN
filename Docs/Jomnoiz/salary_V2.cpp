#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> adj[MAX_N]; // adjacency list for storing edges
long long sal[MAX_N];
int n;

void DFS(int u) {
    cout<<"DFS "<<u<<endl;
    for(int i=1;i<=n;i++) cout<<"Node "<<i<<" Sal "<<sal[i]<<endl;
    for (auto v : adj[u]) {
        sal[v] += sal[u];
        DFS(v);
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
    int u,in;
    for(int i=0;i<m;i++){
        cin >> u >> in;
        // add bonus to parent node
        sal[u] += in;
    }
    DFS(1);

    for(int i=1;i<=n;i++) cout<<sal[i]<<' ';
}