#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> adj[MAX_N]; // adjacency list for storing edges
bool visited[MAX_N]; // nodes should be visited once

int main() {
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

    queue <int> q;
    q.push(1);
    visited[1] = true;
    vector <int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);
        for (auto v : adj[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (auto v : order) cout << v << ' ';
    return 0;
}