#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> adj[MAX_N]; // adjacency list for storing edges
bool visited[MAX_N]; // nodes should be visited once
vector <int> order;

void dfs(int u) {
    order.push_back(u);
    for (auto v : adj[u]) {
        if (visited[v] == false) {
            visited[v] = true;
            dfs(v);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m; // number of nodes and edges
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v; // nodes represent edge

        // undirected graph, push both u,v and v,u
        adj[u].push_back(v);
        adj[v].push_back(u);

        /*
        directed graph, push only u->v
        adj[u].push_back(v);
        */
    }

    visited[1] = true;
    dfs(1);

    for (auto v : order) cout << v << ' ';
    return 0;
}