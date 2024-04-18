#include <bits/stdc++.h>
using namespace std;

const long long MAX_N = 1e11;
// bool arr[MAX_N];


int main(){
    long long last = 1;
    bool *arr = new bool[MAX_N];

    for(int i=1;i<=38;i++){
        last = last * 3 +1;
        // if(last>=MAX_N){
        //     cout<<"Yes\n";
        //     cout<<i;
        //     break;
        // }
    }
    cout<<log(last)/log(10);
}