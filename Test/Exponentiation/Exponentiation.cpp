#include <bits/stdc++.h>
using namespace std;

// ตัวหารตามโจทย์
const int MOD = 1e9+7;

long long expo(long long a, long long b) {
    cout<<"B "<<b<<endl;
    // in this task we assume that 0^0=1.
    if (b == 0) return 1;
    if (b == 1) return a;
    long long res = expo(a, b/2);
    return ((res * res)%MOD * (b%2 ? a : 1)%MOD);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    while (n--) {
        long long a, b; cin >> a >> b;
        cout <<"Ans "<< expo(a, b) << "\n";
    }
}