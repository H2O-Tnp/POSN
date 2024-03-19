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
        if(mp.find(in)==mp.end()){
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
    int lasti=0;
    for(auto i:order){
        tuple<int,int,int> temp = mp[i];
        change += get<0>(mp[lasti]);

        int ordered_id = change+get<0>(temp);
        vector<int> max;
        //            num     freq, 1st last
        //                      0    1   2
        max.push_back(abs(ordered_id - get<1>(temp)));
        max.push_back(abs(get<1>(temp) - (change+1)));
        max.push_back(abs(ordered_id - get<2>(temp)));
        max.push_back(abs(get<2>(temp) - (change+1)));

        sort(max.begin(),max.end(),greater<>());
        cout<<i<<' '<<max.front()<<endl;
        lasti = i;
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