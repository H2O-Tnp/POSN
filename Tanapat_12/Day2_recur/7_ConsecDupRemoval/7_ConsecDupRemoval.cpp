#include <bits/stdc++.h>
using namespace std;

string dupRemove(string s){
    if(s.empty()){
        return "";
    }
    if(s[0] != s[1]){
        return s[0]+dupRemove(s.substr(1));
    }
    else{
        return dupRemove(s.substr(1));
    }
}

int main(){
    string s;
    cin>>s;
    cout<<dupRemove(s);
}