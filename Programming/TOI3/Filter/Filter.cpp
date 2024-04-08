#include <bits/stdc++.h>
using namespace std;

vector<int> win(4005);

int main(){
    int W,H,n;
    cin>>W>>H>>n;
    for(int i=0;i<n;i++){
        int x,a;
        cin>>x>>a;
        for(int j=x;j<x+a;j++){
            win[j]++;
        }
    }
    int cHun=0,cFif=0;
    for(int i=0;i<W;i++){
        int num = win[i];
        if(num==0) cHun++;
        if(num==1) cFif++;
    }
    cout<<cHun*H<<' '<<cFif*H;
}