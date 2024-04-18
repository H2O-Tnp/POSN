#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3+5;
const int MOD_N = 1e9+7;


int main(){
    int n;
    cin>>n;
    
    int dp[MAX_N];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=(i*dp[i-1])%MOD_N;
    }
    cout<<dp[n];
}