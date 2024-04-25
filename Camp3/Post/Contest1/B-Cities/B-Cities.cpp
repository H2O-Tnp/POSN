#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const long long INF = LONG_LONG_MAX;

//           node weight
vector <pair <int, int>> adj[MAX_N];
long long min_dist[MAX_N];
//          node
vector<int> imp;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, m;
    cin >> n >> k >> m;
    while(k--){
        int im; cin>>im;
        imp.emplace_back(im);
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }

    
    long long ans = INT_MAX;
    for (int S = 1; S <= n; S++){
    // pq for keeping the pair of (distance, node)
        for (int i = 1; i <= n; i++) min_dist[i] = INF;
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
        pq.emplace(0, S);
        min_dist[S] = 0;
        while (!pq.empty()) {
            auto [cur_dis, u] = pq.top();
            pq.pop();

            if (cur_dis > min_dist[u]){
                // cout<<"con: "<<cur_dis<<' '<<min_dist[u]<<' '<<u<<endl;
                continue;
            }
        
            for (auto [adj_ver, adj_w] : adj[u]) {
                if (min_dist[u] + adj_w < min_dist[adj_ver]) { // if the new path is shorter (better), replace and use the new one.
                    min_dist[adj_ver] = min_dist[u] + adj_w;
                    pq.emplace(min_dist[adj_ver], adj_ver);
                    // cout<<u<<" emplace: "<<adj_ver<<' '<<min_dist[adj_ver]<<endl;
                }
            }
        }
        long long sum= 0;
        for(auto i:imp){
            sum+=min_dist[i];
        }
        ans = min(ans,sum);
    }
    cout<<ans<<"\n";
    return 0;
}