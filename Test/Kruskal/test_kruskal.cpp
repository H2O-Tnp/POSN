#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

vector<tuple<int,int,int>> edge;
int par[MAX_N];

int find_root(int u){
    if(u == par[u]) return par[u];
    return par[u] = find_root(par[u]);
}

bool merge(int a,int b){
    int u = find_root(a);
    int v = find_root(b);
    if(u==v) return false;
    par[v] = u;
    return true;
}

int main(){
    int n,m;
    
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        edge.emplace_back(w,u,v);
    }
    sort(edge.begin(),edge.end());

    
    int ans = 0;
    for(auto [w,u,v] : edge){
        // cout<<"test\n";
        par[u] = u;
        if(merge(u,v)){
            ans+=w;
        }
    }
    cout<<ans;
}
    
/*
6 15
0 1 4
0 2 4
1 2 2
1 0 4
2 0 4
2 1 2
2 3 3
2 5 2
2 4 4
3 2 3
3 4 3
4 2 4
4 3 3
5 2 2
5 4 3
*/

/*
9 14
0 1 4 
0 7 8 
1 2 8 
1 7 11 
2 3 7 
2 8 2 
2 5 4 
3 4 9 
3 5 14 
4 5 10 
5 6 2 
6 7 1
6 8 6 
7 8 7 
    */