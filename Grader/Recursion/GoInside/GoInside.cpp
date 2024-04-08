#include <bits/stdc++.h>
using namespace std;

string goInside(string str, bool front){
    if(str.length() <= 1) return str;
    string res;
    if(front){
        res += str.front();
        res += str.back();
        res += goInside(str.substr(1, str.length()-2) , false);
        return res;
    }else{
        res += str.back();
        res += str.front();
        res += goInside(str.substr(1, str.length()-2) , true);
        return res;
    }
}

int main(){
    string str;
    cin>>str;
    cout<<goInside(str,true);
}