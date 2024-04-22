#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,r;
    cin>>l>>r;
    // sub 1
    while(r--){
        int X;
        cin>>X;
        while(X--){
            int len;
            cin>>len;
            if(len*2 <= l){
                cout<<"0\n";
            } 
            else if(len == l){
                cout<<l<<"\n";
            }
            else if(l%2==0){
                cout<<(len*2)-l<<"\n";
            }
            else{
                cout<<(len*2)-l<<"\n";
            }
        }
    }
}

/*
10 1 
1 4

10 1 
1 5

9 1 
1 5
*/