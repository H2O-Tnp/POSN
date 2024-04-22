#include <bits/stdc++.h>
using namespace std;

char arr[505][505];
map<char,int> st;
bool visited[4][505][505];
pair<int,int> Start={0,0},End={0,0};
int N,M;

int ar[4]={0,1,0,-1};
int ac[4]={1,0,-1,0};

int rec(char state,char laststate,int r,int c,char lastchar){
    cout<<r<<' '<<c<<"\n";
    cout<<"cur "<<arr[r][c]<<" last "<<lastchar<<" state "<<state<<"\n";
    lastchar = arr[r][c];
    int ans = -1;
    if(arr[r][c]=='E'){
        return 1;
    }
    
    if(arr[r][c]=='p' || arr[r][c]=='j' || arr[r][c]=='b'){
        laststate = state;
        state = toupper(arr[r][c]);
    }

    for(int i=0;i<4;i++){
        int row = r+ar[i];
        int col = c+ac[i];
        if(row == 0||row == N+1||col == 0||col == M+1
        || arr[row][col] == 'S' || arr[row][col] == '#' || visited[st[state]][row][col] == true){
            continue;
        }
        if(arr[row][col]=='P' || arr[row][col]=='J' || arr[row][col]=='B'){
            if(state != arr[row][col]){
                continue;
            }
        }
        if(arr[row][col]=='.' || state == arr[row][col]
           || arr[row][col]=='p' || arr[row][col]=='j' || arr[row][col]=='b'){
            visited[st[state]][r][c] = true;
            ans = max(ans,rec(state,laststate,row, col, lastchar));
            // cout<<ans<<"\n";
        }
    }

    return ans;
}

int main(){
    st['-']=0;
    st['P']=1;
    st['J']=2;
    st['B']=3;
    cin>>N>>M;
    
    // input
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='S'){
                Start = {i,j};
            }
        }
    }
    rec('-','-',Start.first,Start.second,'-');
}

/*
2 5
S.J.b
.jB.E
*/