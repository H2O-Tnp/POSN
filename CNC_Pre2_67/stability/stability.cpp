#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int h[n+1][m+1];
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>h[i][j];
            sum+=h[i][j];
        }
    }
    cout<<sum+k;
}