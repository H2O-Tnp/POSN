#include <bits/stdc++.h>
using namespace std;

vector<pair<int,long long>> adj[70005];
long long dist1[70005];
long long dist2[70005];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int ans =0;
    int N,M;
    cin>>N>>M;
    string xmas;
    string st;
    string ref = "XMAS";
    
    cin>>xmas>>st;
    
    for(int i=1;i<=M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
        
    }
    // cout<<3<<"\n";
    vector<int> test;
    test.push_back(N);
    int cntfind=0,id[4];
    for(int i=0;i<xmas.size();i++){
        if(xmas[i]=='_'){
            id[i]=1;
            test = i;
            cntfind++;
        }
    }
    if(test!=N){
        for(int i=0;i<st.size();i++){
            if(ref[test]==st[i]){
                id[i]=1;
                test = i+2;
                break;
            }
        }
    }
    // cout<<"test "<<test<<"\n";

    //                  w    v
    for(int i=1;i<=N;i++){
        dist1[i]=INT_MAX;
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq1;
    pq1.emplace(0,1);
    dist1[1]=0;
    
    while(!pq1.empty()){
        long long uw;
        int u;
        tie(uw, u) = pq1.top();
        pq1.pop();
        if(uw > dist1[u]) continue;
        pair<int,long long> temp;
        for(auto temp : adj[u]){
            int v = temp.first;
            long long vw = temp.second;
            if(dist1[u] + vw < dist1[v]){
                dist1[v] = dist1[u] + vw;
                pq1.emplace(vw,v);
            }
        }
    }

    ans += dist1[test];
    // cout<<dist1[test]<<"\n";
    if(test!=N){
        for(int i=1;i<=N;i++){
            dist2[i]=INT_MAX;
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq2;
        pq2.emplace(0,N);
        dist2[N]=0;
        while(!pq2.empty()){
            long long uw;
            int u;
            tie(uw, u) = pq2.top();
            pq2.pop();
            if(uw > dist2[u]) continue;
            pair<int,long long> temp;
            for(auto temp : adj[u]){
                int v = temp.first;
                long long vw = temp.second;
                if(dist2[u] + vw < dist2[v]){
                    dist2[v] = dist2[u] + vw;
                    pq2.emplace(vw,v);
                }
            }
        }
        ans += dist2[test];
    }
    // cout<<dist2[test]<<"\n";
    cout<<ans<<"\n";

    return 0;
}