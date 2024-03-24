#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

vector <pair <int, int>> graph[MAX_N];
int dist[MAX_N];
bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int k, x;
        cin >> k >> x;

        while (k--) {
            int a;
            cin >> a;
            graph[a].emplace_back(N + i, x);
            graph[N + i].emplace_back(a, 0);
        }
    }

    for (int i = 0; i < N + M; i++) dist[i] = INF;

    priority_queue <pair <int, int>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u] == true) continue;
        visited[u] = true;
        // cout<<"vis: "<<u<<endl;

        for (auto [v, w] : graph[u]) {
            if (visited[v] == false and dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(-dist[v], v);
            }
        }
    }
    
    if (visited[N - 1] == false) dist[N - 1] = -1;
    cout << dist[N - 1];
    return 0;
}