#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> vec;
    cin>>n;
    while(n--){
        int in;
        cin>>in;
        vec.push_back(in);
    }
    for(int src=0;src<vec.size()-1;src++){
        int idx = src;
        for(int tar=src+1;tar<vec.size();tar++){
            if(vec.at(tar)<vec.at(idx)){
                idx = tar;
            }
        }
        // swap
        swap(vec.at(src),vec.at(idx));
        for(int i=0;i<vec.size();i++) cout<<vec.at(i)<<' ';
        cout<<endl;
    }
}