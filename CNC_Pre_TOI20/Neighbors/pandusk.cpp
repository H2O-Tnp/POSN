#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5+5;
int n, q;
int ne[mxN];
vector<pair<int,ll>> adj[mxN];
ll dist[mxN];
bool vis[mxN];
ll have[mxN];

ll dfs(int u, int prt) {
    ll result = 0;
    vis[u] = true;
    for(auto [v, w] : adj[u]) {
        if(v == prt) continue;
        if (ne[v]) {
            result = max(result, w);
        } 
        else {
            result = max(result, w + dfs(v, u));
        }
    }
    return result;
}

int main()
{   
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> ne[i];        
    }
    for(int i = 0; i < n-1; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    while(q--) {
        int a;
        cin >> a;
        if(ne[a]) {
            cout << "0\n";
            continue;
        }
        // if(have[a]) {
        //     cout<<"have ";
        //     cout << have[a] << '\n';
            
        //     continue;
        // }
        have[a] = dfs(a, a);
        cout << have[a] << '\n';
        // cout << dfs(a, a) << '\n';
    }
    // for(int i = 0; i < n; ++i) cout << can[i] << ' ';
    
}