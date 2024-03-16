#include <bits/stdc++.h>
using namespace std;
int n;

struct Num{
    int num;
    int no;
};

bool compare(Num &n1,Num &n2){
    if(n1.no < n2.no){
        return true;
    }
    return false;
}



int main(){
    cin>>n;
    struct Num arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].num;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].no;
    }
    sort(arr,arr+n,compare);
    for(auto i:arr){
        cout<<i.num<<' ';
    }
}