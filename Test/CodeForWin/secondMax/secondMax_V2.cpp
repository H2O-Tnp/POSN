#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int maxNum = INT_MIN;
    int secondMax = INT_MIN;
    
    for(int i=0;i<n;i++){
        int in;
        cin>>in;
        if(in>maxNum){
            secondMax = maxNum;
            maxNum = in;
        }
        else if(in > secondMax && in != maxNum){
            secondMax = in;
        }
    }
    cout<<secondMax;
}

/*
11
75 -7 2 3 8 6 6 73 38 3 2
*/