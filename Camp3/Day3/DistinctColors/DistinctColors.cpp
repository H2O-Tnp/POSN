#include <bits/stdc++.h>
using namespace std;

int node[200005];
vector<int> adj[200005];
set<int> color[200005];
int cnt[200005];

// current node, parent node
void dfs(int i, int par){
    // store itself
    color[i].emplace(node[i]);
    for(auto j:adj[i]){
        if(j==par){
            continue;
        }
        dfs(j,i);

        if(color[j].size() >= color[i].size()){
            swap(color[i],color[j]);
        }
        for(auto k:color[j]){
            color[i].emplace(k);
        }
    }
    cnt[i] = color[i].size();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>node[i];
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<' ';
    } cout<<"\n";
}