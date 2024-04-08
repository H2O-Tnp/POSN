#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;

        int cid = 0;
        for(int j=0;j<s2.length();j++){
            for(int k=cid;k<s1.length();k++){
                if(s2[j] == s1[k] || s2[j] == toupper(s1[k])){
                    s1[k] = '-';
                    s2[j] = '*';
                    cid = k+1;
                    break;
                }
            }
        }
        // check wrong upper
        bool w_upper = false;
        for(int k=0;k<s1.length();k++){
            if(s1[k] >= 'A' && s1[k] <= 'Z'){
                w_upper = true;
                break;
            }
        }
        if(s2[s2.length()-1] == '*' && !w_upper){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}