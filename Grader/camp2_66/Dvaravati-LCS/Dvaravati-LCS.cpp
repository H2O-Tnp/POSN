#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    string s11,s22;

    s11=s1;
    s22=s2;
    int cnt1=0;
    int cnt2=0;

    vector<int> od1;
    vector<int> od2;
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            if(s1[i]==s2[j]){
                od1.push_back(s1[i]);
                cnt1++;
                s2[j]='-';
                break;
            }
        }
    }
    for(int i=0;i<s22.length();i++){
        for(int j=0;j<s11.length();j++){
            if(s1[i]==s11[j]){
                od1.push_back(s22[i]);
                cnt2++;
                s11[j]='-';
                break;
            }
        }
    }
    cout<<max(cnt1,cnt2);
}