#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
vector<int> arr;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N,M,K;
    cin>>N>>M>>K;
    int last;
    cin>>last;
    arr.emplace_back(0);
    for(int i=1;i<M;i++){
        int in;
        cin>>in;
        arr.emplace_back(in-last-1);
        last = in;
    }
    sort(arr.begin(),arr.end(),greater<int>());
    int ans = 0;
    for(int i=K-1;i<M-1;i++){
        ans+=arr[i];
    }
    cout<<ans<<'\n';
}