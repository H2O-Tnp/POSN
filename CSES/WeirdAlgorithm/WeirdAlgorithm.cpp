#include <bits/stdc++.h>
using namespace std;

int main(){
    long long in;
    cin>>in;
    cout<<in<<' ';
    while(in!=1){
        if(in%2==0){
            in/=2;
        }
        else{
            in*=3;
            in++;
        }
        cout<<in<<' ';
    }
}