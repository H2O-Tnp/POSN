#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

const int MAXN = 2005;
long long arr[MAXN];

int main(){
    int N,Q;
    cin>>N>>Q;

    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    
    if(Q){
        sort(arr+1,arr+N+1);
        int enl,str;
        if(N%2==1){
            enl = (N/2)+1;
            str = enl+1;
        } else {
            enl = N/2;
            str = enl+1;
        }

        ll numl = arr[1];
        ll totall = 0;
        for(int i=2;i<=enl;i++){
            // cout<<num<<' ';
            totall += numl*arr[i];
            numl += arr[i];
        }
        // cout<<totall<<"\n";

        ll numr = arr[str];
        ll totalr = 0;
        for(int i=str+1;i<=N;i++){
            // cout<<num<<' ';
            totalr += numr*arr[i];
            numr += arr[i];
        }
        // cout<<totalr<<"\n";
        cout<<totall+totalr<<"\n";
    } else {
        ll num = arr[1];
        ll total = 0;
        for(int i=2;i<=N;i++){
            // cout<<num<<' ';
            total += num*arr[i];
            num += arr[i];
            
        }
        cout<<total<<"\n";
    }
}