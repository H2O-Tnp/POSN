#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    vector<int> ans;
    for(int i=1;i<=N;i++){
        int in; cin>>in;
        auto it = upper_bound(ans.begin(),ans.end(),in);
        if(it!=ans.end()) *it = in;
        else ans.emplace_back(in);
    }
    cout<<N-ans.size()<<"\n";
}