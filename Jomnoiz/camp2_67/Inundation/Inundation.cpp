#include <bits/stdc++.h>
using namespace std;

const int d[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    vector <vector <int>> table(R + 1, vector <int> (C + 1));
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> table[i][j];
        }
    }

    int L;
    cin >> L;

    vector <int> ans;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (table[i][j] > L) continue;

            queue <pair <int, int>> q;
            table[i][j] = L + 1;
            q.emplace(i, j);
            int cnt = 1;
            while (!q.empty()) {
                auto [ux, uy] = q.front();
                q.pop();

                for (int k = 0; k < 8; k++) {
                    int vx = ux + d[k][0], vy = uy + d[k][1];
                    if (vx < 1 or vx > R or vy < 1 or vy > C) continue;

                    if (table[vx][vy] <= L) {
                        table[vx][vy] = L + 1;
                        q.emplace(vx, vy);
                        cnt++;
                    }
                }
            }
            ans.push_back(cnt);
        }
    }
    
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (auto &v : ans) cout << v << '\n';
    return 0;
}