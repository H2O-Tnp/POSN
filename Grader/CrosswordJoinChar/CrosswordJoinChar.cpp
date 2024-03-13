#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    // cout<<int('A')<<" "<<int('a');
    cin>>n;
    string str[n];
    cin>>str[0];
    // cout<<str[0][0];
    for(int i=1; i<n; i++){
        cin>>str[i];
        for(int j=0; j<str[i-1].size();j++){
            for(int k=0; k<str[i].size(); k++){
                if(str[i-1][j]==str[i][k]){
                    str[i-1][j]-=32;
                }
            }
        }
        cout<<str[i-1]<<endl;
    }
}