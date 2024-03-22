#include <bits/stdc++.h>
using namespace std;

int main(){
    string word = {"Tanapat"};
    // cout<<log2(8)+1;
    // for(int i=1;i<log2(word.length())+1;i++){
    //     cout<<i;
        // cout<<word[i&(pow(2,word.length()-1))];
    // }
    int num=1;
    for(int i=1;i<=5;i++){
        cout<<num<<endl;
        num<<=1;
    }

}