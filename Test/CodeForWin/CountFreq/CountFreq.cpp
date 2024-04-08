#include <bits/stdc++.h>
using namespace std;

int main(){
    // declare
    int n;
    cin>>n;
    int arr[n];
    int freq[n]={0};
    
    // input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // process
    for(int i=0;i<n-1;i++){
        int cnt=1;
        if(freq[i]!=-1){
            for(int j=i+1;j<n;j++){
                if(arr[i] == arr[j]){
                    cnt++;
                    freq[j] = -1;
                }
            }
            freq[i] = cnt;
        }
    }

    // print result
    for(int i=0;i<n;i++){
        if(freq[i] != -1){
            cout<<arr[i]<<' '<<freq[i]<<endl;
        }
    }
}

/*
10
5 10 2 5 50 5 10 1 2 2
*/