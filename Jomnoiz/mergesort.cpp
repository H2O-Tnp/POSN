#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int a[MAX_N];
int n;

void solve(int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);

    // at this point, both arrays are sorted.
    vector <int> L, R;
    for (int i = l; i <= mid; i++) L.push_back(a[i]);
    for (int i = mid + 1; i <= r; i++) R.push_back(a[i]);

    int i = 0, j = 0, k = l;
    while (i < L.size() and j < R.size()) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++, k++;
        }
        else {
            a[k] = R[j];
            j++, k++;
        }
    }

    while (i < L.size()) {
        a[k] = L[i];
        i++, k++;
    }
    while (j < R.size()) {
        a[k] = R[j];
        j++, k++;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    solve(1, n);

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout<<endl;
    return 0;
}

