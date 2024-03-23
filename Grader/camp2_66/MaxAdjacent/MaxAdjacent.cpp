#include <bits/stdc++.h>
using namespace std;

int main(){
    string in;
    vector<int> arr;
    arr.emplace_back(-INT_MAX);
    while(true){
        cin>>in;
        if(in[0] >= 'a' && in[0] <= 'z') break;
        int num=stoi(in);
        arr.emplace_back(num);
    }
    arr.emplace_back(-INT_MAX);
    for(int i=1;i<arr.size();i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            cout<<arr[i]<<' ';
        }
    }
}