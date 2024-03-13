#include <bits/stdc++.h>
using namespace std;

int main(){
    string in;
    cin >> in;
    for(int num=0; num<in.size();num++){
        char n = in[num];
        if(n >= 'A' && n <= 'F'){
            cout<<int(n)-55<<"x16^"<<in.size()-num-1;
        }
        else{
            cout<<n<<"x16^"<<in.size()-num-1;
        }
        if(num!=in.size()-1) cout<<'+';
    }
}

/*
3AB785CDAB23451567ABC986543210FFA321
22
*/