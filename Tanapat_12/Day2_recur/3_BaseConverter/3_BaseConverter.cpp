#include <bits/stdc++.h>
using namespace std;

string BaseConv(int dec,int base){
    // cout<<dec<<' '<<base<<endl;
    if(dec<base){
        return to_string(dec);
    }
    return BaseConv(dec/base,base) + to_string(dec%base);
}

int main(){
    int dec,base;
    cin>>dec>>base;
    string res = BaseConv(dec,base);
    cout<<res;
}