#include <bits/stdc++.h>
using namespace std;

int jump(int n,vector<int> cost,vector<int> mindis){
    if(n<=0) return 0;
    if(mindis[n]!=0) return mindis[n];
    mindis[n] = cost[n] + min(jump(n-2,cost,mindis),jump(n-1,cost,mindis));
    return mindis[n];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> cost(n+1);
    vector<int> mindis(n+1);
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    cout<<jump(n,cost,mindis);
}
/*
3 2
3 2 4
*/