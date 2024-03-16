#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int res=0;
    int fac[12] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800};
    string in;
    cin>>in;
    for(int i=0;i<n;i++){
        res+=(in[i]-65)*fac[n-i-1];
        for(int j=1+1;j<n;j++){
            if(in[i]<in[j]){
                in[j]--;
            }
        }
    }
    cout<<res;
}