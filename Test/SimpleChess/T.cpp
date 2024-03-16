#include <bits/stdc++.h>
using namespace std;

int main(){
    int board[9][9], chess[6][2];
    // set chess at out of board
    for(int i=0;i<6;i++){
        chess[i][0]=0;
        chess[i][1]=0;
    }

    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            board[i][j]=0;
        }   
    }
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int c,x,y;
        cin>>c>>x>>y;
        chess[c][0]=y;
        chess[c][1]=x;
    }
    for(int i=1;i<=5;i++){
        board[chess[i][0]][chess[i][1]]=i;
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}