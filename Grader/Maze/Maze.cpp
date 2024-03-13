#include <bits/stdc++.h>
using namespace std;

void sol(int y, int x,vector<vector<int>>& vec){
    // for(int i=0;i<6;i++){
    //     for(int j=0;j<6;j++){
    //         cout<<vec[i][j]<<" ";
    //     }cout<<endl;
    // }
    if(vec[y][x]==0){
        if(y>0){
            sol(y-1,x,vec);
        }x
        if(x>0){
            sol(y,x-1,vec);
        }
        sol(y+1,x,vec);
        sol(y,x+1,vec);
    }
    if(vec[y][x]==1) return;
    if(vec[y][x]==2) return;
    if(vec[y][x]==3){
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                cout<<vec[i][j]<<" ";
            }cout<<endl;
        }
    }
    // if(vec[y][x]==4) return;
}

int main(){
    int m,n;
    cin>>m>>n;
    int stx,sty;
    vector<vector<int>> maze(n, vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            if(maze[i][j]==4){
                sty=i;
                stx=j;
            }
        }
    }
    cout<<sty<<" "<<stx<<endl;
    if(sty>0){
        sol(sty-1,stx,maze);
    }
    if(stx>0){
        sol(sty,stx-1,maze);
    }
    sol(sty+1,stx,maze);
    sol(sty,stx+1,maze);

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<maze[i][j]<<" ";
    //     }cout<<endl;
    // }


}