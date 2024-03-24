#include <bits/stdc++.h>  // Include standard C++ libraries
using namespace std;      // Use the std namespace

const int MAX_N = 2e5 + 5;  // Maximum number of nodes

// Array to store parent nodes for union-find
int parent[MAX_N];

// Finds the root node of a given node using path compression
int find_root(int u) {
    if (u == parent[u]) {
        // Base case: node is its own root
        return u;
    }
    return parent[u] = find_root(parent[u]);  // Path compression
}

// Merges two sets represented by their root nodes
bool merge(int a, int b) {
    int u = find_root(a), v = find_root(b);
    // Check if already in the same set
    if (u == v) {
        return false;
    }

    // Merge by setting parent of v to u
    parent[v] = u;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);  // Optimize input/output

    int n, m;  // Number of nodes and edges
    cin >> n >> m;

    // Store edges as tuples (weight, node1, node2)
    vector<tuple<int, int, int>> edge;
    while (m--) {
        int u, v, w;  // Node1, Node2, Weight
        cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
    }

    // Sort edges in ascending weight order
    sort(edge.begin(), edge.end());

    int ans = 0;  // Variable to store the total weight of the MST
    for (auto [w, u, v] : edge) {  // Iterate through sorted edges
        if (merge(u, v) == true) {  // Attempt to merge sets
            ans += w;  // If merge successful, add weight to MST
        }
    }

    cout << ans;  // Print the final MST weight
    return 0;
}