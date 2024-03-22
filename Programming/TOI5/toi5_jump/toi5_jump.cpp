#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,dis;
    scanf("%d %d",&n,&dis);
    int gap[n+1];
    int maxlen=-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&gap[i]);
        maxlen=max(maxlen,gap[i]);
    }

    int max_line=1;
    for(int i=1;i<n;i++){
        if(maxlen-gap[i] < dis) break;
        for(int j=i+1;j<=n;j++){
            // cout<<gap[i]<<' '<<gap[j]<<aendl;
            if(gap[j]-gap[i]>dis){
                max_line = max(max_line,j-i-1);
                break;
            }
            else if(gap[j]-gap[i]==dis){
                max_line = max(max_line,j-i);
                break;
            }
        }
    }
    // for(auto i:gap){
    //     cout<<i<<' ';
    // }cout<<endl;
    printf("%d",max_line);
}

/*
11 6
3
6
7
9
10
11
13
16
18
19
20
*/