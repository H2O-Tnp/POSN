#include <bits/stdc++.h>
using namespace std;

int add(int n){
    if(n==1) return 1;
    return add(n-1) + n;
}

int main(){
    int n;
    cin>>n;
    cout<<add(n);
}