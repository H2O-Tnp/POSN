#include <bits/stdc++.h>
using namespace std;

bool cmp(int n, pair<int, int> const& p)
{
    if(p.first >= n){
        return true;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin>>N;
    //         val, point
    vector<pair<int,int>> ans;
    map<int,int> mp;
    ans.emplace_back(INT_MIN,-1);
    int test=0;
    for(int i=1;i<=N;i++){
        int in; cin>>in;
        auto it = upper_bound(ans.begin(),ans.end(),in,cmp);

        if(it!=ans.end()){
            auto itt = it;
            itt--;
            int point = itt->first;
            mp[in]=point;
            *it = make_pair(in,point);
        }
        else {
            if(it == ans.end()){
                test = it->first;
                cout<<"test\n";
            }
            int point = ans.back().first;
            mp[in]=point;
            ans.emplace_back(in,point);
        }
    }
    cout<<test<<"\n\n";
    vector<int> st;
    st.emplace_back(ans.back().first);
    int id = ans.back().first;
    while(1){
        if(mp[id]==INT_MIN) break;
        st.emplace_back(mp[id]);
        id = mp[id];
    }
    sort(st.begin(),st.end());
    cout<<ans.size()-1<<"\n";
    for(int i:st){
        cout<<i<<' ';
    } cout<<"\n";
}

/*
10
6 3 4 8 10 5 7 1 9 2
*/