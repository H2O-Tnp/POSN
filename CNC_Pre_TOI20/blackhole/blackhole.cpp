#include <bits/stdc++.h>
using namespace std;

//           galaxy  planet
vector<int> adj[705][1005];

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int sum = 0;
    
    for(int i=1;i<=M;i++){
        int E; cin>>E;
        set<int> test;
        for(int j=1;j<=E;j++){
            int u,v; cin>>u>>v;
            adj[i][u].emplace_back(v);
            adj[i][v].emplace_back(u);
            test.emplace(u);
            test.emplace(v);
        }
        if(i<=K+1) sum += test.size();
    }
    cout<<sum<<"\n";
    // if(K==0){
    //     for(int j=1;j<=E;j++){
    // }
    // else{
    //     cout<<N*(K+1)<<"\n";
    // }
}