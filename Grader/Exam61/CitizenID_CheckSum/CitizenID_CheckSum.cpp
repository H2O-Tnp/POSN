#include <bits/stdc++.h>
using namespace std;

int main(){
    // std::cout<<'C'-'A'+1;
    // cout<<'1'-'0';
    // cout<<endl<<endl;
    string in;
    cin>>in;
    int sum=0;
    for(int i=0;i<in.size()-1;i++){
        if(i==1){
            sum+=in[i]-'A'+1;
        }
        else{
            sum+=in[i]-'0';
        }
    }
    int amod = sum%11;
    if(amod <= 1){
        amod = 1-amod;
    }
    else if(amod > 1){
        amod = 11-amod;
    }

    if(amod == in.back()-'0'){
        cout<<"T "<<sum;
    }
    else{
        cout<<"F "<<sum;
    }
}

/*
0,1 : Name : year(4) : oerder(4) : checksum
*/