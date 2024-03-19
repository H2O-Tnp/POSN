#include <bits/stdc++.h>
using namespace std;

const int coy[4]={0,-1,0,1};
const int cox[4]={-1,0,1,0};

void flood(int y,int x,int n,int m,vector<vector<char>> &mp){
    for(int l=0;l<4;l++){
        int row = y+coy[l];
        int col = x+cox[l];
        if(row >= 0 && row < n && col >= 0 && col < m){
            if(mp[row][col]=='.')
            {
                mp[row][col]='#';
                flood(row,col,n,m,mp);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mp(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mp[i][j];
        }
    }
    

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='.'){
                cnt++;
                flood(i,j,n,m,mp);
            }
        }   
    }
    cout<<cnt;
}

/*
10 10
####.###..
#.######.#
##.######.
###.###..#
##.####..#
#####..###
#.########
#.####.#.#
#####..##.
######.###
*/