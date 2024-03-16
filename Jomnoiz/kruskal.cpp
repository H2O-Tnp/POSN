#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int parent[MAX_N];

int find_root(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_root(parent[u]);
}

bool merge(int a, int b) {
    int u = find_root(a), v = find_root(b);
    if (u == v) return false;

    parent[v] = u;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <tuple <int, int, int>> edge;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;

        edge.emplace_back(w, u, v);
        // edge.push_back({w, u, v});
    }

    sort(edge.begin(), edge.end());

    int ans = 0;
    for (auto [w, u, v] : edge) {
        if (merge(u, v) == true) ans += w;
    }
    cout << ans;
    return 0;
}