#include <bits/stdc++.h>
using namespace std;
\
const int mxN = 1e5+5;
vector<int> adjrev[mxN];
bool open[mxN];

int main(){
    int N,M,Q;
    cin>>N>>M>>Q;
    while(M--){
        int a,b;
        cin>>a>>b;
        adjnor[a].emplace_back(b);
        adjrev[b].emplace_back(a);
    }
    stack<int> st;
    while(Q--){
        int T,X;
        cin>>T>>X;
        if(T==1){
            open[x]=false;
        } else {
            st.emplace(X);
        }
    }
}