#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    while (N--) {
        string V1, V2;
        cin >> V1 >> V2;

        int n = V1.size(), m = V2.size();
        V1.insert(V1.begin(), '#');
        V2.insert(V2.begin(), '#');

        vector <vector <bool>> dp(n + 1, vector <bool> (m + 1)); 
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (V1[i] >= 'A' and V1[i] <= 'Z') {
                    if (V1[i] == V2[j]) dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                    if (V1[i] - 32 == V2[j]) dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                }
            }
        }
        if (dp[n][m] == true) cout << "YES\n";
        else cout << "NO\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (dp[i][j]==1) cout<<1<<' ';
                else cout<<0<<' ';
            }
            cout<<"\n";
        }
    }
    return 0;
}