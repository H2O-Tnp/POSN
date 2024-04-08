#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const long long INF = 1e18 + 7;

vector <pair <int, int>> adj[MAX_N];
long long dist[MAX_N][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K, T;
    cin >> N >> M >> K >> T;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (int i = 1; i <= N; i++) dist[i][0] = dist[i][1] = INF;

    // 5 4 3 2 1 -> -1 -2 -3 -4 -5
    priority_queue <tuple <long long, int, int>> pq;
    //         w node cop
    pq.emplace(0, 1, 0);
    dist[1][0] = 0;
    while (!pq.empty()) {
        auto [d, u, k] = pq.top();
        pq.pop();

        if (-d > dist[u][k]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u][k] + w < dist[v][k]) {
                dist[v][k] = dist[u][k] + w;
                pq.emplace(-dist[v][k], v, k);
            }
            if (k == 0 and dist[u][0] + K < dist[v][1]) {
                dist[v][1] = dist[u][0] + K;
                pq.emplace(-dist[v][1], v, 1);
            }
        }
    }

    long long ans = min(dist[N][0], dist[N][1]);
    if (ans <= T) cout << "Happy Winnie the Pooh :3\n" << ans;
    else cout << "No Honey TT";
    return 0;
}