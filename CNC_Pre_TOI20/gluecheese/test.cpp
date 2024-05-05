#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int MAXN = 1005;
int arr[MAXN][MAXN];
ll dpin[MAXN][MAXN];
 
int N,M,Ci,Cj;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M>>Ci>>Cj;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            dpin[i][j] = LONG_LONG_MAX;
        }
    }

    int adi[4] = {1,0,-1,0};
    int adj[4] = {0,-1,0,1};
 
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> q;
    dpin[Ci][Cj] = arr[Ci][Cj];
    q.emplace(dpin[Ci][Cj],Ci,Cj);
    while(!q.empty()){
        auto [x,i,j] = q.top();
        q.pop();
        
        for(int a=0;a<4;a++){
            int ii = i+adi[a];
            int jj = j+adj[a];
            if(ii==N+1 || ii==0 || jj==M+1 || jj==0) continue;
            if(dpin[i][j] + arr[ii][jj] < dpin[ii][jj]){
                dpin[ii][jj] = dpin[i][j] + arr[ii][jj];
                q.emplace(dpin[ii][jj],ii,jj);
            }
        }
    }
 
    ll minout = dpin[1][1];
    minout = min(minout,dpin[N][1]);
    minout = min(minout,dpin[1][M]);
    minout = min(minout,dpin[N][M]);
 
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout<<dpin[i][j]+minout-arr[Ci][Cj]<<" ";
        }
        cout<<"\n";
    }
}
 
/*
3 3 2 2
9 4 3
0 6 4
8 1 14
 
5 6 2 5
9 4 3 0 6 4
8 1 14 4 13 15
0 11 11 13 15 8
0 2 5 10 14 9
11 7 11 15 3 6
*/