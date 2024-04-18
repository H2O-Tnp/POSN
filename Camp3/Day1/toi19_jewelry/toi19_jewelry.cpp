#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin>>N;
    string s;
    cin>>s;

    long long ans = 0;
    long long sum = 0;
    int i=0;

    stack<int> st;
    queue<int> q;
    for(;i<N;i++){
        if(s[i]=='T'){
            int prev = 0;
            if(!st.empty()){
                prev = st.top();
                st.pop();
            }
            sum += i+1-prev;
            q.emplace(i+1);
            if(i+1<=N && s[i+1]=='F'){
                while(!q.empty()){
                    st.emplace(q.front());
                    q.pop();
                }
            }
        }
        ans+=sum;
    }
    cerr<<"ans ";
    cout<<ans<<"\n";
}