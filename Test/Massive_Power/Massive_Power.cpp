#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    if(x>y) cout<<y+int(log10(pow(5,x-y)))+1;
    else cout<<x+int(log10(pow(2,y-x)))+1;
}