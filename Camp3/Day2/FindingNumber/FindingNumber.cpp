#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n+1);

    for(int i=1;i<=n;i++){
        cin>>vec.at(i);
    }
    sort(vec.begin(),vec.end());
    int tar;
    cin>>tar;

    // bin
    int l=1,r=n,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        ans=vec[mid];
        if(ans == tar){
            break;
        }
        else if(vec[mid] < tar){
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    if(ans == tar)
        cout<<"Yes";
    else cout<<"No";
}

/*
6
16 59 63 48 52 55
52
*/