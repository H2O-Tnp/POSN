#include <bits/stdc++.h>
using namespace std;

/*
* Problem: Given a graph with N nodes and M edges, find the minimum distances
*          from source node S to all other nodes in the graph.
*          Print -1 if a path does not exist.
*/

// Constants for maximum nodes and representing infinity
const int MAX_N = 1e5 + 5;  // Maximum number of nodes allowed
const int INF = 1e9 + 7;    // Representing infinity

// Adjacency list to store edges connected to each node
// (node, weight) pairs
vector<pair<int, int>> adj[MAX_N];

// Array to store minimum distances from source node S
int dist[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);  // Optimize input/output

    int N, M, S;                                // Number of nodes, edges, source node
    cin >> N >> M >> S;                          // Read input values

    while (M--) {                               // Read edges
        int u, v, w;                             // Nodes and weight of an edge
        cin >> u >> v >> w;

        // Undirected graph: add edges in both directions
        adj[u].emplace_back(v, w);               // Add edge (u, v) with weight w
        adj[v].emplace_back(u, w);               // Add edge (v, u) with weight w
    }

    // Initialize all distances to infinity
    for (int i = 1; i <= N; i++) dist[i] = INF;

    // Priority queue to store nodes and their distances for processing
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, S);                              // Add source node S with distance 0
    dist[S] = 0;                                  // Set distance of source node to 0

    // Dijkstra's algorithm
    while (!pq.empty()) {
        auto [d, u] = pq.top();                      pq.pop();  // Extract node with highest distance

        if (d > dist[u]) continue;                 // Outdated distance, skip

        for (auto [v, w] : adj[u]) {               // Explore neighbors of u
            if (dist[u] + w < dist[v]) {           // If a shorter path is found through u
                dist[v] = dist[u] + w;             // Update distance of neighbor v
                pq.emplace(dist[v], v);          // Add neighbor v with updated distance to queue
            }
        }
    }

    // Print the minimum distances (or -1 if unreachable)
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) cout << "-1 ";      
        else cout << dist[i] << ' ';
    }

    return 0;
}
