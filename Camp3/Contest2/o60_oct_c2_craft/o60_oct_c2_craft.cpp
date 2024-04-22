#include <bits/stdc++.h>
using namespace std;

int arr[22];

int main(){
    long long n,w;
    cin>>n>>w;
    long long num=0;
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        w-=(arr[i]/2);
    }
    // cout<<w<<"\n";
    // cout<<pow(2,n-1)<<"\n";
    // cout<<-1<<"\n";
    num=w*pow(2,n-1);
    if(num<=0){
        cout<<-1<<"\n";
    } else {
        cout<<num<<"\n";
    }
    
}