#include <bits/stdc++.h>
using namespace std;

string reorder(string s, bool forward){
    if(s.empty()) return "";
    if(forward){
        if(s[0]=='A'){
            forward = false;
        }
        return s[0] + reorder(s.substr(1),forward);
    }
    else{
        if(s[s.length()-1]=='A'){
            forward = true;
        }
        return s[s.length()-1] + reorder(s.substr(0, s.length()-1),forward);
    }
}

int main(){
    string s;
    cin>>s;
    string res = reorder(s,true);
    cout<<res;
}