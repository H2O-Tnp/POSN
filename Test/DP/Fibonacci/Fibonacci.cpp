#include <bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> ar){
    if(n<=2) return 1;
    if(ar[n]!=0){
        return ar[n];
    }
    ar[n] = fib(n-1,ar) + fib(n-2,ar);
    return ar[n];
}

int main(){
    int n;
    cin>>n;
    vector<int> ar(n+1);
    cout<<fib(n,ar);
}