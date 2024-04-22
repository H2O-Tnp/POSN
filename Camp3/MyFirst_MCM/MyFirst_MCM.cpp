#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int arr[105];

int main(){
    int N; cin>>N;
    for(int i=1;i<=N+1;i++){
        cin>>arr[i];
    }

    for(int sz=2;sz<=N;sz++){
        for(int i=0;i<N+1 -sz; i++){
            int j = i+sz-1;
            dp[i][j] = INT_MAX;
            for(int k=i;k<=j-1;k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }
        }
    }
    cout<< dp[1][N-1];
}