#include <bits/stdc++.h>
using namespace std;

/*
Given a graph with N node M edge. 
Print the minimum distance between S to every node in the graph.
If the path does not exist, print -1
*/

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

vector <pair <int, int>> adj[MAX_N];
int dist[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, S;
    cin >> N >> M >> S;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;

        // undirected graph
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (int i = 1; i <= N; i++) dist[i] = INF;

    // pq for keeping the pair of (distance, node)
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.emplace(0, S);
    dist[S] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) { // if the new path is shorter (better), replace and use the new one.
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) cout << "-1 "; // the path does not exist
        else cout << dist[i] << ' ';
    }
    return 0;
}