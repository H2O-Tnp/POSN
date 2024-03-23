#include <bits/stdc++.h>
using namespace std;

string conv(int num,int base){
    if(num==0) return "";
    int mod = num%base;
    // cout<<mod<<endl;
    return conv(num/base,base) + char(mod+'0');
}

int main(){
    // printf("%c",1+'0');
    int dec,base;
    cin>>dec>>base;
    // cout
    cout<<conv(dec,base);
}