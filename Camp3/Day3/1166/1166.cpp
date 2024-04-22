#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin>>N>>M;
    char in[N+2][M+2] ;
    char vec[N+2][M+2] ;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>in[i][j];
            vec[i][j]=in[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(in[i][j]=='#'){
                vec[i-1][j] = '-';
                vec[i][j-1] = '-';
                vec[i+1][j] = '-';
                vec[i][j+1] = '-';
            }
        }
    }

    int addr[4]={0,1,0,-1};
    int addc[4]={1,0,-1,0};
    int maxf = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(vec[i][j]=='.'){
                int cnt = 0;
                queue<pair<int,int>> q;
                q.emplace(i,j);
                while(!q.empty()){
                    auto [r,c] = q.front();
                    q.pop();
                    if(vec[r][c]!='.'){
                        continue;
                    }
                    cnt++;
                    vec[r][c]='!';
                    
                    for(int a=0;a<4;a++){
                        int row = r+addr[a];
                        int col = c+addc[a];
                        if(row == 0 || row == N+1 || col == 0 || col == M+1){
                            continue;
                        }
                        if(vec[row][col] == '!'){
                            continue;
                        }
                        if(vec[row][col] == '.'){
                            q.emplace(row,col);
                        }
                    }
                }
                maxf = max(maxf,cnt);
            }
        }
    }
    cout<<maxf<<"\n";
    cerr<<"end\n";
}