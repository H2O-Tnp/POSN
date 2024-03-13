#include <bits/stdc++.h>
using namespace std;

string merge(string str1, string str2){
    // cout<<str1<<' '<<str2<<endl;
    if(str1.empty() || str2.empty()){
        //base
        return str1+str2;
    }

    if(str1[0]<str2[0]){
        return str1[0]+merge(str1.substr(1),str2.substr(1));
    }
    else{
        return str2[0]+merge(str1.substr(1),str2.substr(1));
    }
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    string s;
    string res = merge(str1,str2);
    cout<<res;
}

/*
NARUTO
OROCHIMARU
*/