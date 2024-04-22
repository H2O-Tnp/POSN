#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
    }
    int l=1,r=2e5;
    int ans=0,mid=0;
    while(l<=r){
        mid = (l+r)/2;
        int x = mid;

        // quick sum
        vector<int> qs(n+1); qs[0]=0;
        for(int i=1;i<=n;i++){
            if(vec[i] < x){
                qs[i] = qs[i-1] -1;
            } else {
                qs[i] = qs[i-1] +1;
            }
        }
        // sliding windows
        int minqs = 0;
        for(int rs=k;rs<=n;rs++){
            minqs = min(minqs,qs[rs-k]);
            if(qs[rs] > minqs){
                // found x
                ans = x;
                l = mid + 1;
                break;
            }
        }
        if(ans != x){
            r = mid - 1;
        }
    }
    cout<<ans<<"\n";
}