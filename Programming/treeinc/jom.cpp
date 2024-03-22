#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5 + 5;

vector <int> adj[MAX_N];
int dist[MAX_N];

void dfs(int u) {
    dist[u] = 1;
    for (auto v : adj[u]) {
        if (dist[v] == -1) dfs(v);
        dist[u] = max(dist[u], dist[v] + 1);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;

        if (u > v) swap(u, v);
        adj[u].push_back(v);
    }

    int ans = 0;
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= N; i++) {
        if (dist[i] != -1) continue;
        dfs(i);
        ans = max(ans, dist[i]);
    }
    cout << ans;
    return 0;
}