#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAX_N = 1e17;

int main(){
    ll N; cin>>N;
    ll l=0,r=MAX_N;

    while(l<=r){
        ll mid = (l+r)/2;
        if(23*mid + 98*(mid/12) < N){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout<<l*7;
}