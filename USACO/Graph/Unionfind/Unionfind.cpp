#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+5;
int parent[MAX_N];

int find_root(int u){
    if(u==parent[u]) return u;
    return parent[u]=find_root(parent[u]);
}

void merge(int a,int b){
    int u=find_root(a), v=find_root(b);
    if(u==v) return;
    parent[v] = u;
}
 
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N,Q;
    cin>>N>>Q;
    for(int i=0;i<=N;i++){
        parent[i]=i;
    }
    for(int i=1;i<=Q;i++){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==1){
            // check
            cout<<(find_root(u)==find_root(v))<<"\n";
        } else{
            // add edge
            merge(u,v);
        }
    }
}

/*
4 7
1 0 1
0 0 1
0 2 3
1 0 1
1 1 2
0 0 2
1 1 3
*/