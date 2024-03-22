#include <bits/stdc++.h>
using namespace std;


set<int> nugset;

int main(){
    int in;
    cin>>in;
    if(in < 6){
        cout<<"no";
        return 0;
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                int nug = 6*i+9*j+20*k;
                if(nug==0) continue;
                if(nug <= in){
                    nugset.emplace(nug);
                }
            }
        }
    }
    for(auto i:nugset){
        if(i>in) break;
        cout<<i<<endl;
    }
}