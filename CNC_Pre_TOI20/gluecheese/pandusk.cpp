#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define tuu tuple<ll,int,int>

const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const ll INF = 1.5e18;
const int mxN = 1005;
int n, m, A, B;
ll arr[mxN][mxN];
ll dist[mxN][mxN];
bool vis[mxN][mxN];
priority_queue<tuu, vector<tuu>, greater<tuu>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> A >> B;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            dist[i][j] = INF;
        }
    }

    dist[A][B] = 0;
    pq.emplace(dist[A][B], A, B);
    while(!pq.empty()) {
        auto [d, r, c] = pq.top();
        pq.pop();
        if(vis[r][c]) continue;
        vis[r][c] = true;
        for(int i = 0; i < 4; ++i) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr < 1 || nc < 1 || nr > n || nc > m) continue;
            if(vis[nr][nc]) continue;
            if(dist[nr][nc] > d + arr[nr][nc]) {
                dist[nr][nc] = d + arr[nr][nc];
                pq.emplace(d + arr[nr][nc], nr, nc);
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            // cout << dist[i][j] << ' ';
            ll ans = min({dist[1][1], dist[1][m], dist[n][1], dist[n][m]});
            ans += dist[i][j] + arr[A][B];
            cout << ans << ' ';
        }
        cout << '\n';
    }
}