#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
vector<int> adj[MAX_N];
bool visit[MAX_N];
int edge_cnt[MAX_N];

int main(){
    int N;cin>>N;
    for(int i=1;i<=N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b); edge_cnt[a]++;
        adj[b].emplace_back(a); edge_cnt[b]++;
    }
    //          start stop
    map<int,int> link;
    for(int i=1;i<=N;i++){
        
        for(int j=1;j<=N;j++){
            cout<<link[j]<<' ';
        } cout<<"\n";

        cout<<"node "<<i<<"\n";

        // leaf
        if(edge_cnt[i]==1){
            cout<<"leaf\n";
            int adj_node = adj[i].front();
            if(visit[adj_node]){
                cout<<"ex leaf\n";
                // do somethings
                visit[i]=true;
                
                for(auto u:adj[adj_node]){
                    if(u==i) continue;
                    if(edge_cnt[u]==1){
                        cout<<"pair ex leaf\n";
                        cout<<i<<"->"<<adj_node<<"\n";
                        cout<<u<<"->"<<i<<"\n";
                        edge_cnt[u]++;
                        link[i]=adj_node;
                        link[u]=i;
                        break;
                    }
                }
                continue;
            }
        }
        if(visit[i]) continue;
        for(auto u:adj[i]){
            cout<<"normal link\n";
            if(visit[u]) continue;
            link[i]=u; visit[i] = true;
            link[u]=i; visit[u] = true;
            break;
        }
        
    }
    cout<<"\n";

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