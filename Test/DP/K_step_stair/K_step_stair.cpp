#include <bits/stdc++.h>
using namespace std;

int jump(int n,int k,vector<int> arr){
    if(arr[n]==-1) return 0;
    if(n<=1) return 1;
    if(arr[n]!=0){
        return arr[n];
    }
    for(int i=1;i<=k;i++){
        if(n-i < 0) break;
        arr[n] += jump(n-i,k,arr);
    }
    return arr[n];
}

int main(){
    int n,k,b;
    cin>>n>>k>>b;
    vector<int> arr(n+1);
    arr[0]=1;
    arr[1]=1;
    while(b--){
        int in;
        cin>>in;
        arr[in]=-1;
    }
    cout<<jump(n,k,arr);
}