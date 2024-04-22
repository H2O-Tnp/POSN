#include <bits/stdc++.h>
using namespace std;

void div(vector<string>& pic,int lx,int rx,int ly,int ry){
    pair<int,int> max1[4+1]={};
    pair<int,int> max0[4+1]={};

    for(int j=r/2;j<=r;j++){
        for(int k=c/2;k<=c;k++){
            if(pic[j][k]=='1') cnt1++;
            else cnt0++;
        }
    }
    max1[1].first=cnt1;
    max1[1].second=i;
    max0[1].first=cnt0;
    max0[1].second=i;

    sort(max1+1,max1+4);
    sort(max0+1,max0+4);
    // cout<<max1[1].second;
}

int main(){
    int N; cin>>N;
    vector<string> pic(N+1);
    for(int i=1;i<=N;i++){
        cin>>pic[i];
    }
    for(auto i:pic){
        cerr<<i<<"\n";
    }
    div(pic,N,N);
}

/*
4
0001
0001
0011
1110
*/