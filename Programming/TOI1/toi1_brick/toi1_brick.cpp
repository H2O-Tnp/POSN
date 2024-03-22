#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string bo[n+1];
    for(int i=1;i<=n;i++){
        cin>>bo[i];
    }
    for(int j=0;j<m;j++){
        int in;
        cin>>in;
        for(int k=1;k<=in;k++){
            for(int i=1;i<=n;i++){
                if(bo[i][j]=='O' || bo[i][j]=='#'){
                    bo[i-1][j] = '#';
                    break;
                }
                if(i==n){
                    bo[i][j] = '#';
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            cout<<bo[i][j];
        }cout<<endl;
    }
}