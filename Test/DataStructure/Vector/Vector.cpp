#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v1{1,2,3,4,5,6,7,8};
    for(int i:v1){
        cout<<i<<" ";
    }cout<<'\n';
    v1[3] = 99;
    for(int i:v1){
        cout<<i<<" ";
    }cout<<'\n';
}