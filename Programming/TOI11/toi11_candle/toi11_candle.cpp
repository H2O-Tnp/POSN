#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e3+5;
int adx[8] = {0,1,0,-1,1,-1,-1,1};
int ady[8] = {1,0,-1,0,1,-1,1,-1};

string pl[MAX_N];
int visited[MAX_N][MAX_N];

int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>pl[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<pl[i][j];
    //     }cout<<endl;
    // }

    int cnt=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            // cout<<i<<' '<<j<<endl; //
            if(pl[i][j]=='1' && !visited[i][j]){
                cnt++;
                // cout<<"cnt "<<cnt<<endl;
                queue<pair<int,int>> flood;
                flood.emplace(i,j);
                while(!flood.empty()){
                    auto [cy,cx] = flood.front();
                    flood.pop();
                    for(int a=0;a<8;a++){
                        int yy = cy+ady[a];
                        int xx = cx+adx[a];
                        // cout<<yy<<' '<<xx<<" add"<<endl;
                        if(yy == 0 || yy == m+1 || xx == -1 || xx == n || visited[yy][xx]){
                            continue;
                        }
                        visited[yy][xx] = 1;
                        if(pl[yy][xx]=='1'){
                            flood.emplace(yy,xx);
                            // cout<<yy<<' '<<xx<<" 1\n";
                        }
                        
                    }
                }
            }
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<visited[i][j];
    //     }cout<<endl;
    // }
    cout<<cnt;
}