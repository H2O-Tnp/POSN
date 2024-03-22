#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100+5;
vector<pair<int,int>> adj[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
pair<int,int> par[MAX_N][MAX_N];
//    y   x
// pair<int,int> co[MAX_N];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            char in;
            cin>>in;
            if(in=='R'||in=='B'){
                if(j+1<=b){
                    adj[i][j].emplace_back(i,j+1);
                    adj[i][j+1].emplace_back(i,j);
                }
            }
            if(in=='D'||in=='B'){
                if(i+1<=a){
                    adj[i][j].emplace_back(i+1,j);
                    adj[i+1][j].emplace_back(i,j);
                }
            }
        }
    }
    queue<pair<int,int>> q;
    q.emplace(1,1);
    visited[1][1]=true;
    par[1][1]={1,1};
    while(!q.empty()){
        auto [uy,ux] = q.front();
        // cout<<uy<<' '<<ux<<endl;
        q.pop();
        for(auto [vy,vx]:adj[uy][ux]){
            if(vy==par[uy][ux].first && vx==par[uy][ux].second){
                continue;
            }
            if(!visited[vy][vx]){
                visited[vy][vx]=true;
                par[vy][vx]={uy,ux};
                q.emplace(vy,vx);
            }
            else {
                printf("%d\n%d %d",vy+vx-1,vy,vx);
                return 0;
            }
        }
    }
}