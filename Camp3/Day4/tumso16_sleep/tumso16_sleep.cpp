#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int l,r;
        cin>>l>>r;
        dp[l]++;
        dp[r]--;
    }
    int maxx=0; int id=1;
    for(int i=1;i<100005;i++){
        dp[i]+=dp[i-1];
        if(dp[i] > maxx){
            maxx = dp[i];
            id = i;
        }
    }
    if(maxx == N){
        cout<<"yes "<<id<<"\n";
    } else {
        cout<<"no "<<id<<"\n";
    }
}