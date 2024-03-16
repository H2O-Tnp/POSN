#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> num;
    while(n--){
        int in;
        cin>>in;
        num.push_back(in);
    }
    sort(num.begin(),num.end());
    bool one = true;
    for(int i=0;i<num.size();i++){
        
        if(i%2==0){
            if(i+1==num.size()){
                cout<<num[i]<<' ';
            }
            else cout<<num[i+1]<<' ';
        }
        else{
            cout<<num[i-1]<<' ';
        }
    }


}