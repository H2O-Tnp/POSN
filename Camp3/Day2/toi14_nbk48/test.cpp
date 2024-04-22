#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;
const int mxN = 1e5+5;
int n,q;
ll qs[mxN], a;

bool check(int mid, ll E) {
    return E >= qs[mid];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; ++i){
        cin >> a;
        qs[i] = qs[i-1] + a;
    }

    ll mn = INF;
    for(int i = n; i >= 1; --i) {
        qs[i] = min(mn, qs[i]);
    }

    while(q--) {
        int x;
        cin >> x;
        int l=1, r=n, ans = 0;
        while(l <= r) {
            int mid = (l+r)/2;
            if(x >= qs[mid]) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << ans << '\n';
    }

}
