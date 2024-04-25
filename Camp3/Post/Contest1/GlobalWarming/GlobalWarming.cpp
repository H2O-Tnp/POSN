#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin>>N>>X;
    vector<int> vec(N+1);
    map<int,int> par;
    par[0] = -1;
    for(int i=1,t;i<=N;i++){
        cin>>t;
        vec[i] = t;
    }

    //          data parent
    vector<pair<int,int>> ans;
    pair<int,int> last = make_pair(-1,-1);
    ans.emplace_back(-1,-1);
    for(int i=1;i<=N;i++){
        auto it = upper_bound(ans.begin()++,ans.end(),make_pair(vec[i],0));
        if(it != ans.end()){
            if(it==--ans.end()){
                last = *it;
            }
            // cerr<<"replace\n";
            // cerr<<"vec[i] = "<<vec[i]<<"\n";
            it--;
            par[vec[i]] = it->first;
            // cerr<<"par[vec[i]] = "<<par[vec[i]]<<"\n";
            it++;
            *it = make_pair(vec[i],par[vec[i]]);
            // cerr<<"\n";
        } else {
            // cerr<<"push_back\n";
            // cerr<<"vec[i] = "<<vec[i]<<"\n";
            par[vec[i]] = ans.back().first;
            // cerr<<"par[vec[i]] = "<<par[vec[i]]<<"\n";
            // break;
            ans.emplace_back(vec[i],par[vec[i]]);
            // cerr<<"\n";
        }
    }
    cout<<ans.size()<<"\n";
    cout<<"\n";
    int lp = ans.size()-1;
    int res =last.first;
    while(lp--){
        cout<<res<<' ';
        res = par[res];
    }


}

/*
8 10
7 3 5 12 2 7 3 4
*/