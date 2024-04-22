#include <bits/stdc++.h>
using namespace std;

char arr[1005][1005];
int R,C;

int adr[4]={0,1,0,-1};
int adc[4]={1,0,-1,0};

void flood(int r,int c){
    // cerr<<"flood\n";
    if(arr[r][c]=='.'){
        arr[r][c]='-';
        for(int i=0;i<4;i++){
            int row = r+adr[i];
            int col = c+adc[i];
            if(row == 0||row == R+1||col == 0||col == C+1){
                continue;
            }
            if(arr[row][col]=='.'){
                flood(row, col);
            }
        }
    }
}

void check(int r,int c,int& cnt){
    // cerr<<"check\n";
    if(arr[r][c]=='X'){
        
        arr[r][c]='Y';

        for(int i=0;i<4;i++){
            int row = r+adr[i];
            int col = c+adc[i];
            if(row == 0||row == R+1||col == 0||col == C+1){
                continue;
            }
            if(arr[row][col]=='-'){
                cnt++;
            }
        }
        // check recur
        for(int i=0;i<4;i++){
            int row = r+adr[i];
            int col = c+adc[i];
            if(row == 0||row == R+1||col == 0||col == C+1){
                continue;
            }
            if(arr[row][col]=='X'){
                check(row, col,cnt);
            }
        }
    }
}

void printArr(char ar[][1005]){
    cerr<<"\nPrint\n";
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cerr<<ar[i][j];
        }
        cerr<<"\n";
    }
}

int main(){
    
    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>arr[i][j];
        }
    }
    flood(1,1);
    // printArr(arr);

    int ans=0;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(arr[i][j]=='X'){
                int cnt = 0;
                check(i,j,cnt);
                ans = max(ans,cnt);
            }
        }
    }
    cout<<ans<<"\n";
}

/*
8 7
.......
.XXXXX.
.X...X.
.X.X.X.
.X.X.X.
.X...X.
.XXXXX.
.......

4 6
......
.X.X..
.X.XX.
......

4 6
......
.X.X..
..X.X.
......
*/