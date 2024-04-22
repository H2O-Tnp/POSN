#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    //          num id
    vector<pair<int,int>> vec(N+1);
    for(int i=1;i<=N;i++){
        int in;
        cin>>in;
        vec[i].first = in;
        vec[i].second = i;
    }
    sort(vec.begin(),vec.end());

    // Q
    int L,R,C;
    while(Q--){
        cin>>L>>R>>C;
        pair<int,int> p1 = {C,L-1};
        pair<int,int> p2 = {C,R};
        auto st = upper_bound(vec.begin(),vec.end(),p1);
        auto end = upper_bound(vec.begin(),vec.end(),p2);

        cout<<end-st<<"\n";
    }
} 

/*
10 8
1 2 1 2 1 2 3 2 3 3
1 2 1
1 3 1
1 4 2
1 5 2
2 5 4
2 6 3
6 9 0
7 10 3
*/