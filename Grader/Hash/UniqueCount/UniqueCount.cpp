#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // unordered_map<int,int> num(5000000);
    unordered_map<int,int> num(1000000);
    while(n--){
        int in;
        cin>>in;
        if(num.find(in)==num.end()) num[in]=1;
    }
    cout<<num.size();
}