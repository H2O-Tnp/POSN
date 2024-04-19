#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <int> qsp(n + 1), qsn(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        qsp[i] = qsp[i - 1];
        qsn[i] = qsn[i - 1];
        if (a > 0) qsp[i] += a;
        else qsn[i] -= a;
    }
    
    // for(int i=1;i<=n;i++){
    //     cerr<<qsn[i]<<' ';
    // }cerr<<"\n";
    // for(int i=1;i<=n;i++){
    //     cerr<<qsp[i]<<' ';
    // }cerr<<"\n";

    while (m--) {
        int x, h;
        cin >> x >> h;

        int l = ++x, r = n, ans = x - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (qsn[mid] - qsn[x - 1] < h) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << qsp[ans] - qsp[x - 1] << '\n';
    }
    return 0;
}