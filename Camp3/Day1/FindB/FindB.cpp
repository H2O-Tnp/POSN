#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 3e5+5;
int arr[MAX_N];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        int sumone = 0;
        cin>>n>>q;
        
        long long qsone[n+1];
        long long qs[n+1];
        qs[0] = 0;
        qsone[0] = 0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            qsone[i]=qsone[i-1];
            qs[i]=qs[i-1]+arr[i];
            if(arr[i]==1){
                qsone[i]++;
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            if(l==r){
                cout<<"NO\n";
                continue;
            }
            // cerr<<"qs1 "<<qsone[r]-qsone[l-1]<<"\n";
            int qs1 = qsone[r]-qsone[l-1];
            // r-l+1 -> all to "1"
            // qs1 -> all 1 to 2
            if(qs[r]-qs[l-1] < r-l+1+qs1){
                cout<<"NO\n";
            } else {
                cout<<"YES\n";
            }
        }
    }
}

/*
1
5 4
1 2 1 4 5
1 5
4 4
3 4
1 3

*/