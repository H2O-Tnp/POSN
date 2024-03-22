#include <bits/stdc++.h>
using namespace std;

/*
Given a graph with N node M edge. 
Print the minimum distance between S to every node in the graph.
If the path does not exist, print -1
*/

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

//           node weight
vector <pair <int, int>> adj[MAX_N];
int min_dist[MAX_N];

void addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, S;
    // cin >> N >> M >> S;
    N=9;
    S=0;
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);


    // while (M--) {
    //     int ver_u, ver_v, weight;
    //     cin >> ver_u >> ver_v >> weight;

    //     // undirected graph
    //     adj[ver_u].emplace_back(ver_v, weight);
    //     adj[ver_v].emplace_back(ver_u, weight);
    // }

    for (int i = 1-1; i <= N-1; i++) min_dist[i] = INF;

    // pq for keeping the pair of (distance, node)
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.emplace(0, S);
    min_dist[S] = 0;
    while (!pq.empty()) {
        auto [cur_dis, u] = pq.top();
        pq.pop();

        if (cur_dis > min_dist[u]){
            cout<<"con: "<<cur_dis<<' '<<min_dist[u]<<' '<<u<<endl;
            continue;
        }
    
        for (auto [adj_ver, adj_w] : adj[u]) {
            if (min_dist[u] + adj_w < min_dist[adj_ver]) { // if the new path is shorter (better), replace and use the new one.
                min_dist[adj_ver] = min_dist[u] + adj_w;
                pq.emplace(min_dist[adj_ver], adj_ver);
                cout<<u<<" emplace: "<<adj_ver<<' '<<min_dist[adj_ver]<<endl;
            }
        }
    }

    for (int i = 1-1; i <= N-1; i++) {
        if (min_dist[i] == INF) cout << "-1 "; // the path does not exist
        else cout << min_dist[i] << ' ';
    }
    return 0;
}