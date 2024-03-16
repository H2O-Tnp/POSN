#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string in[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    sort(in,in+n);
    for(auto i:in) cout<<i<<endl;
}

/*
3
ILOVEYOU
SILPAKORN
NICEONE
*/