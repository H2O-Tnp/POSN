#include <bits/stdc++.h>
using namespace std;

int main(){
    int col,row;
    cin>>col>>row;
    int mat[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]=0;
        }
    }
    int block[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>block[i][j];
        }
    }
    int in_col;
    cin>>in_col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            // if
            if(j==in_col-1 && i==row-2){
                for(int k=0;k<2;k++){
                    for(int l=0;l<2;l++){
                        mat[i+k][j+l]=block[k][l];
                    }
                    
                }
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
}

/*
col row
*/
/*
1 2
3 4
*/