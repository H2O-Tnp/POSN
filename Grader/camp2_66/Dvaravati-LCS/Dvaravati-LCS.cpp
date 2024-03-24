#include <bits/stdc++.h>
using namespace std;

string ans;

string lcs(string& s1,string& s2,int x1,int x2){
    if(x1==0 || x2==0){
        return "";
    }
    if(s1[x1]==s2[x2]){
        return lcs(s1,s2,x1-1,x2-1)+s1[x1];
    }
    else{
        return max(lcs(s1,s2,x1-1,x2),lcs(s1,s2,x1,x2-1));
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    string ans = lcs(s1,s2,s1.length(),s2.length());
    // reverse(ans.begin(),ans.end());
    char yep='y';
    // if(ans.length() <= s1.length()/2){
    //     yep='n';
    // }
    cout<<resstr<<'\n'<<maxc<<'\n'<<yep;
}