#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int parent[MAX_N];

int find_root(int u) {
    if (u == parent[u]) return u;
    return find_root(parent[u]);
}

bool merge(int a, int b) {
    int u = find_root(a), v = find_root(b);
    if (u == v) return false;

    parent[v] = u;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // N : vertices
    // Q : Edges
    int N, Q;
    cin >> N >> Q;

    int ans = N+1;
    for (int i = 1; i <= N; i++) parent[i] = i;
    while (Q--) {
        int u, v;
        cin >> u >> v;

        if (merge(u, v) == true) ans--;
    }
    cout << ans << '\n';
    return 0;
}

/*
7 7
1 0
0 2
5 3
3 4
6 7

6 5
3 6
*/