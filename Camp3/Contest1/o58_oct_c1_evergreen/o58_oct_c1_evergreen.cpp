#include <bits/stdc++.h>
using namespace std;


// brute 
int main(){
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
    }
    long long sum = 0;
    long long plus = 1;
    int i=0;
    while(sum*N<=K){
        sum+=plus;
        plus+=2;
        i++;
    }
    cout<<i-1<<"\n";
    // cout<<sum;

}