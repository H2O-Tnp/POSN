#include <bits/stdc++.h>
using namespace std;

int jump(int n,vector<int> arr){
    if(n<=1) return 1;
    if(arr[n]!=0){
        return arr[n];
    }
    return jump(n-1,arr) + jump(n-2,arr) + jump(n-3,arr);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;

    cout<<jump(n,arr);
}