#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string left,right;
    // for(int i=0;i<n;i++){
    //     char in;
    //     cin>>in;
    //     left[i]=in;
    // }
    cin>>left>>right;

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    int cnt=0;
    int lQ=0;
    int rQ=0;

    for(int i=0;i<n;i++){
        if(left[i]=='?'){
            lQ++;
        }
        for(int j=0;j<n;j++){
            if(left[i]==right[j]){
                left[i]='-';
                right[j]='-';
                cnt++;
            }
            if(right[j]=='?'){
                rQ++;
                right[j]='-';
            }
        }
    }
    int res = cnt;
    if(n-cnt >= lQ){
        res+=lQ;
    }
    else{
        res+=n-cnt;
    }

    if(n-cnt >= rQ){
        res+=rQ;
    }
    else{
        res+=n-cnt;
    }

    // for(auto i:left){
    //     cout<<i<<' ';
    // }cout<<endl;
    // for(auto i:right){
    //     cout<<i<<' ';
    // }cout<<endl;
    cout<<res;
}

/*
7
??bga?b
zabbbc?
*/