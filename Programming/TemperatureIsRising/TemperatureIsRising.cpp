#include <bits/stdc++.h>
using namespace std;

bool visited[27][27];
int maxT=0;

int main(){
    int m;
    cin>>m;
    int arr[27][27];
    int sx,sy;
    cin>>sy>>sx;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]==100){
                visited[i][j] = true;
            }
        }
    }
    int ad_x[4] = {0,1,0,-1};
    int ad_y[4] = {1,0,-1,0};

    queue<pair<int,int>> q;
    q.emplace(sx,sy);
    maxT=arr[sx][sy];
    visited[sx][sy]=true;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int xx = x+ad_x[i];
            int yy = y+ad_y[i];
            if(xx==0 || yy==0 || xx==m+1 || yy==m+1 || arr[xx][yy] <= arr[x][y] || visited[xx][yy]) continue;
            visited[xx][yy]=true;
            maxT = max(maxT,arr[xx][yy]);
            q.emplace(xx,yy);
        }
    }
    cout<<maxT;
}