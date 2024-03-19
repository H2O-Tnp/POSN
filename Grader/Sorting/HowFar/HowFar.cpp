#include <bits/stdc++.h>
using namespace std;

//            num     freq, 1st last
unordered_map<int,tuple<int,int,int>> mp(5000000);
vector<int> order;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    int max=0;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(mp.find(mp[in])==mp.end()){
        // if(get<0>(mp[in])==0){
            get<1>(mp[in])=i;
            order.push_back(in);
        }
        get<0>(mp[in])++;
        get<2>(mp[in])=i;
        if(in > max) max = in;
    }
    sort(order.begin(),order.end());
    int change=0;
    int last=0;

    // max = test;//test

    // unor map key travers
    // for(int i=1;i<=max;i++){
    for(auto i:order){
        // if(find(mp[i])==mp.end()) continue;
        if(get<0>(mp[i])==0) continue;
        change += get<0>(mp[i-1]);
        last = change+get<0>(mp[i]);
        int n1 = abs(last - get<1>(mp[i]));
        int n2 = abs(get<2>(mp[i]) - (change+1));
        cout<<i<<' ';
        if(n1 > n2){
            cout<<n1<<endl;
        }
        else {
            cout<<n2<<endl;
        }
    }
}

/*
1:0 7
2:3 6
3:2 8
*/

/*
12
4 3 2 1 5 1 2 1 3 6 5 4

12
4 3 2 1 5 1 2 1 3 8 5 4
*/