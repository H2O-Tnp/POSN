#include <bits/stdc++.h>
using namespace std;

bool compare(string &num1, string &num2){
    if(num1.size() < num2.size()){
        return true;
    }
    if(num1.size() == num2.size()){
        for(int i=0;i<num1.size();i++){
            if(num1[i] < num2[i]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    string num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n,compare);
    for(auto i:num){
        cout<<i<<' ';
    }
}