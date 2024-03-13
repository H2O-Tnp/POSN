#include <bits/stdc++.h>
using namespace std;

string alterMerge(string s1, string s2, int order){
    // cout<<s1<<' '<<s2<<' '<<order<<endl;
    if(s1.empty() || s2.empty()) return "";

    if(order == 1)
        return s1[0] + alterMerge(s1.substr(1), s2.substr(1), 2);
    else
        return s2[0] + alterMerge(s1.substr(1), s2.substr(1), 1);

}

int main(){
    string s1,s2;
    int ord;
    cin>>s1>>s2>>ord;
    string res = alterMerge(s1,s2,ord);
    cout<<res;
}