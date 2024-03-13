#include <bits/stdc++.h>
using namespace std;

int main(){
    string in;
    cin >> in;
    int num;
    cin>>num;
    char n = in[in.size()-num-1];
    if(n >= 'A' && n <= 'F'){
        cout<<int(n)-55<<"x16^"<<num;
    }
    else{
        cout<<n<<"x16^"<<num;
    }
}

/*
3AB785CDAB23451567ABC986543210FFA321
22
*/