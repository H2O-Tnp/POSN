#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string in;
        cin>>in;
        int num = in[in.size()-1]-48;
        if(num==2&&in.size()==1) cout<<"T\n";
        else if(num%2==0) cout<<"F\n";
        else cout<<"T\n";
    }
}

/*
3
8
7
15
*/