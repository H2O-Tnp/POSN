#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5+5;
int arr[MAX_N];
int qscp[MAX_N];
int qspr[MAX_N];


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int sumcp=0;
    int sumpr=0;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]<0){
            sumpr-=arr[i];
        }
        else {
            sumcp+=arr[i];
        }
        qspr[i]=sumpr;
        qscp[i]=sumcp;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<qspr[i]<<' ';
    // }cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     cout<<qscp[i]<<' ';
    // }cout<<"\n";

    while(m--){
        int x,h;
        cin>>x>>h;
        
        // req -> h
        int l=++x,r=n,mid,ans=x-1;
        while(l<=r){
            mid = (l+r)>>1;
            if(qspr[mid] - qspr[x-1] < h){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout<<qscp[ans]-qscp[x-1]<<"\n";
    }
}

/*
8 6
-10 -3 5 6 -20 3 4 0
0 3
0 13
0 14
2 1
2 500000000
6 1
*/