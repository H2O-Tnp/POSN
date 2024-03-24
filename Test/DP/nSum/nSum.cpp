#include <bits/stdc++.h>
using namespace std;

int nSum(int n){
    int dp[n+1];
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1] + i;
    }
    return dp[n];
}

int main(){
    int N;
    cin>>N;
    cout<<nSum(N);
}