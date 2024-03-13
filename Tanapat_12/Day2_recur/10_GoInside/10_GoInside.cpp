#include <bits/stdc++.h>
using namespace std;

string goInside(string str, bool front) {
    // cout<<str[0]<<' '<<str[str.length()-1]<<endl;
    if(str.length()<2){
        return str;
    }
    if(front){
        return str.substr(0,1) + str[str.length()-1] + goInside(str.substr(1,str.length()-2),false);
    }
    else{
        return str[str.length()-1] + str.substr(0,1) + goInside(str.substr(1,str.length()-2),true);
    }
}

int main(){
    string s;
    cin>>s;
    cout<<goInside(s, true);
}