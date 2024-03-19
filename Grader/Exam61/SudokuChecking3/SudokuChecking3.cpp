#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> mat(10);
    for(int i=1;i<=9;i++){
        mat[i].push_back(0);
        for(int j=1;j<=9;j++){
            int in;
            cin>>in;
            mat[i].push_back(in);
        }
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(mat[i][j]==0){
                // row
                int same_r[10]={0};
                for(int c=1;c<=9;c++){
                    same_r[mat[i][c]]++;
                }
                // col
                int same_c[10]={0};
                for(int r=1;r<=9;r++){
                    same_c[mat[r][j]]++;
                }
                // box
                int same_b[10]={0};
                int box_row = i-((i-1)%3);
                int box_col = j-((j-1)%3);
                for(int r=box_row;r<=box_row+2;r++){
                    for(int c=box_col;c<=box_col+2;c++){
                        same_b[mat[r][c]]++;
                    }
                }
                cout<<i<<' '<<j<<' ';
                for(int s=1;s<=9;s++){
                    if(same_r[s]==0 && same_c[s]==0 && same_b[s]==0){
                        cout<<s<<' ';
                    }
                }
                cout<<endl;
            }
        }
    }
}