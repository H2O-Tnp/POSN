#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    int maxNum = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>maxNum){
            maxNum = arr[i];
        }
    }
    int secondMax = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > secondMax && arr[i] != maxNum){
            secondMax = arr[i];
        }
    }
    cout<<secondMax;
}

/*
11
73 -7 2 3 8 6 6 75 38 3 2
*/