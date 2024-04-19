#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> vec(n + 1);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int x, h;
    cin >> x >> h;

    int l = ++x, r = n, ans = x - 1;
    while (l <= r)    {
        int mid = (l + r) / 2;

        // left
        if (qsn[mid] - qsn[x - 1] < h)
            l = mid + 1, ans = mid;
        // right
        else
            r = mid - 1;
    }
    cout << qsp[ans] - qsp[x - 1] << '\n';
    return 0;
}