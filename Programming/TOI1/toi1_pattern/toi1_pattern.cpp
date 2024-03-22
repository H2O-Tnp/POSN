#include <bits/stdc++.h>
using namespace std;
bool cot[50005][71];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    int maxr=0;
    for(int i=1;i<=n;i++){
        int row,col,num;
        cin>>row>>col>>num;
        maxr=max(maxr,row);
        for(int j=col;j<col+num && j<=70;j++) cot[row][j]=true;
    }
    for(int i=1;i<=maxr;i++){
        for(int j=1;j<=70;j++){
            if(cot[i][j]==true)cout<<"x";
            else cout<<"o";
        } cout<<"\n";
    }
}