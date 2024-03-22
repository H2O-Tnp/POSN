#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=arr[0];
    int st=-1;
    int en=-1;
    for(int i=0;i<n;i++){
        int cnt=arr[i];
        for(int j=i+1;j<n;j++){
            cnt+=arr[j];
            if(cnt>max){
                max = cnt;
                st=i;
                en=j;
            }
        }
    }
    if(st==-1 || max<0){
        cout<<"Empty sequence";
    }
    else{
        for(int i=st;i<=en;i++){
            cout<<arr[i]<<' ';
        }cout<<endl;
        cout<<max;
        
    }
}