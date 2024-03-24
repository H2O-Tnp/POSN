#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5+5;
int dp [2][MAX_N];


int jump(int n,int &k,int dp[][MAX_N]){
    if(n<=1) return dp[0][1];
    if(dp[1][n]!=0) return dp[1][n];
    int minC=INT_MAX;
    for(int i=1;i<=k;i++){
        minC = min(minC,jump(n-i,k,dp));
    }
    dp[1][n]=dp[0][n]+minC;
    return dp[1][n];
}

int main(){
    int N,k;
    cin>>N>>k;
    for(int i=1;i<=N;i++){
        cin>>dp[0][i];
    }
    cout<<jump(N,k,dp);
}