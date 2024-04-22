#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct tup {
    int dis, node, mask;
    bool operator<(const tup &o) const {
        return dis > o.dis;
    }
};

vector<pair<ll, ll>> g[50010];
ll dp[50010][20], n, m, u, v, w, val=0, cd, cn, cv, nv;
unordered_map<char, ll> mp;
priority_queue<tup> pq; // tdist, node, val
string s1, s2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    mp['X'] = 8; mp['M'] = 4; mp['A'] = 2; mp['S'] = 1;
    cin >> s1 >> s2;
    s2 = "  " + s2;
    while(m--) {
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    for(int i=1; i<=n; i++) {
        for(int j=0; j<16; j++) {
            dp[i][j] = 1e18;
        }
    }
    for(char i: s1) val |= mp[i];
    pq.push({0, n, val});
    while(pq.size()) {
        cd = pq.top().dis;
        cn = pq.top().node;
        cv = pq.top().mask;
        pq.pop();
        if(cd > dp[cn][cv]) continue;
        dp[cn][cv] = cd;
        if(cn == 1 && cv == 15) {
            cout << cd;
            return 0;
        }
        for(auto i: g[cn]) {
            nv = cv | mp[s2[cn]];
            pq.push({cd + i.first, i.second, nv});
        }
    }
    cout << dp[1][15];
    return 0;
}
