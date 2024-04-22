#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    vector<int> vec(N+1);
    pair<int,int> head;
    for(int i=1;i<=N;i++){
        cin>>vec[i];
        if(head.first < vec[i]){
            head.first = vec[i];
            head.second = i;
        }
    }
    // cout<<head.first<<"\n";
    // cout<<head.second;
    long long maxans = 0;
    for(int t=1;t<=N;t++){
        long long ans = vec[t];
        long long maxMon = vec[head.second];
        //for left
        // cerr<<ans<<"\n";
        for(long long i=head.second-1;i>=1;i--){
            if(vec[i]<=maxMon){
                ans += vec[i];
                maxMon = vec[i];
            }
            else{
                ans += maxMon;
            }
            // cerr<<ans<<"\n";
        }
        
        // for right
        maxMon = vec[head.second];
        for(long long i=head.second+1;i<=N;i++){
            if(vec[i]<=maxMon){
                ans += vec[i];
                maxMon = vec[i];
            }
            else{
                ans += maxMon;
            }
            // cerr<<ans<<"\n";
        }
        maxans = max(ans,maxans);
    }
    cout<<maxans<<"\n";
}