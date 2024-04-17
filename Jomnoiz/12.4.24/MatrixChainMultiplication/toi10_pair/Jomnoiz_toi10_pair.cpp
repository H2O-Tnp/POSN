#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

char A[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    // num of input
    int N;
    cin >> N;

    // input
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 
    for (int sz = 2; sz <= N; sz++) {
        for (int l = 1, r = sz; r <= N; l++, r++) {
            cerr << "l " << l << " | r " << r << "\n";

            if (A[l] == A[r]) dp[l][r] = dp[l + 1][r - 1] + 1;
            cerr << "dp[l][r] " << dp[l][r] << "\n";

            for (int x = l; x < r; x++) {
                dp[l][r] = max(dp[l][r], dp[l][x] + dp[x + 1][r]);
                cerr << "dp[l][x] " << dp[l][x] << "\n";
            }
            cerr << "dp[l][r] " << dp[l][r] << "\n";
        }
    }
    cout << dp[1][N];
    return 0;
}

/*
4
U B O U

6
U B N B O U
*/