#include <bits/stdc++.h>
using namespace std;

long long qs[100005];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int X;
        cin>>X;
        qs[i]=qs[i-1]+(X-m/2);
    }

    // cerr<<"quick\n";
    // for(int i=1;i<=n;i++){
    //     cerr<<qs[i]<<' ';
    // } cerr<<"\n";

    vector<long long> ans;
    ans.emplace_back(0);
    for(int i=1;i<=n;i++){
        if(qs[i] < 0) continue;
        auto it = lower_bound(ans.begin(),ans.end(),qs[i]);
        if(it != ans.end()){
            *it = qs[i];
        } else {
            ans.emplace_back(qs[i]);
        }
    }
    cout<<lower_bound(ans.begin(),ans.end(),qs[n])-ans.begin()<<"\n";
}

/*
5 100
60 48 20 90 49

12 100
60 48 40 56 59 57 45 48 51 52 53 54
*/