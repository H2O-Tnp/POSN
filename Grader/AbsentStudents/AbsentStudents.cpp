#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    unordered_map<int,int> test(5e4);

    for(int l=0;l<12;l++){
        while(1){
            int in;
            cin>>in;
            if(in==0){
                break;
            }
            test[in]++;
        }
    }
    
    vector<pair<int,int>> ans;
    auto it=test.begin();
    while (it != test.end()) { 
        int id = it->first; 
        int count = it->second; 
        if(count<10){
            ans.emplace_back(id,count);
        }
        it++; 
    }
    sort(ans.begin(),ans.end());
    auto vit=ans.begin();
    while (vit != ans.end()) { 
        int id = vit->first; 
        int count = vit->second;
        cout << id << " " << count << "\n";
        vit++; 
    }
}