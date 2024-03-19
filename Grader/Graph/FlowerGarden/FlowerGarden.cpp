#include <bits/stdc++.h>
using namespace std;


const int MAX_N = 1e6+5;
vector<int> adj[MAX_N];
vector<pair<int,int>> flow;
bool visited[MAX_N];

void dfs(int curV){
    visited[curV]=true;
    for(auto i:adj[curV]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        pair<int,int> p;
        cin>>p.first>>p.second;
        flow.push_back(p);
    }
    for(auto i:flow){
        if(i.first)
    }

    double cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<(cnt+2-1)/2;
    // cout<<cnt;
}