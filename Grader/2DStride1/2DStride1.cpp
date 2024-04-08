#include <bits/stdc++.h>
using namespace std;

int main(){
    int in;
    cin>>in;
    int ar[in+1];
    for(int i=1;i<=in;i++){
        ar[i]=i;
    }
    for(int j=0;j<in;j++){
        for(int i=1;i<=in;i++){
            int id=i-j;
            if(id<=0){
                id+=in;
            }
            cout<<ar[id]%10<<' ';
        }
        cout<<"\n";
    }
}