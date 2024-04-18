#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    long long sum = 0, ans = 0;
    map <long long, int> cnt;
    cnt[x] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        sum += a;
        // ans += qs(r)
        ans += cnt[sum];
        // qs(r)++
        cnt[sum + x]++;
    }
    cout << ans;
    return 0;
}