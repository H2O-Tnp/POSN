#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,Q; cin>>N>>Q;
    vector<int> qs(N+1);
    qs[0]=0;
    int in;
    for(int i=1;i<=N;i++){
        cin>>in;
        qs[i]=qs[i-1]+in;
    }
    for(int i=N-1;i>=1;i--){
        qs[i]=min(qs[i],qs[i+1]);
    }

    while(Q--){
        int req; cin>>req;
        int l=1,r=N,mid,ans=0;
        while(l<=r){
            mid = (l+r)/2;
            if (req >= qs[mid]){
                ans = mid;
                l = mid + 1;
            } else {
                
                r = mid - 1;
            }
        }
        cout<<ans<<"\n";
    }
}