#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
vector<int> adj[MAX_N];
vector<int> arr(MAX_N);
bool visit[MAX_N];

int main(){
    int N;cin>>N;
    for(int i=1;i<=N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b); edge_cnt[a]++;
        adj[b].emplace_back(a); edge_cnt[b]++;
        arr[a]=a;
    }
    //          start stop
    map<int,int> link;

    stack<int> st;
    st.emplace(0);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(visit[u]) continue;
        visit[u]=true;

        if(adj[u].size()==1){ // leaf
            int v = adj[u].top();
            arr[u] = v;
            arr[v] = u;
        }

        for(auto v:adj[u]){
            
        }
    }

    for(int j=1;j<=N;j++){
        cout<<link[j]<<' ';
    } cout<<"\n";
}

/*
7
4 2
5 7
3 4
6 3
1 3
4 5


9
1 2
2 9
2 3 
3 4
4 5
5 6
5 7
5 8

7
1 7
6 1
1 2
3 1
1 4
1 5

4
1 2
2 3
3 4

*/