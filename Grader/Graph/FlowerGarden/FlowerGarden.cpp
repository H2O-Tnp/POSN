#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+5;

vector<int> adj[MAX_N];
bool visited[MAX_N];
//            y   x   id
vector<tuple<int,int,int>> flow;

void dfs(int curV){
    visited[curV]=true;
    for(auto i:adj[curV]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

bool Comp_y(tuple<int,int,int>& a, tuple<int,int,int>& b){
    return (get<0>(a) < get<0>(b));
}

bool Comp_x(tuple<int,int,int>& a, tuple<int,int,int>& b){
    return (get<1>(a) < get<1>(b));
}

void print_Flow(vector<tuple<int,int,int>>& flow){
    for(auto i:flow){
        cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<endl;
    }
    cout<<endl;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        tuple<int,int,int> temp;
        cin>>get<0>(temp)>>get<1>(temp);
        get<2>(temp)=i;
        flow.emplace_back(temp);
    }

    sort(flow.begin(),flow.end(),Comp_y);
    tuple<int,int,int> last_flow = flow.front();
    for(auto i=flow.begin()++;i!=flow.end();i++){
        if(get<0>(*i) == get<0>(last_flow)){
            adj[get<2>(last_flow)].push_back(get<2>(*i));
            adj[get<2>(*i)].push_back(get<2>(last_flow));
        }
        last_flow = *i;
    }

    sort(flow.begin(),flow.end(),Comp_x);
    last_flow = flow.front();
    for(auto i=flow.begin()++;i!=flow.end();i++){
        if(get<1>(*i) == get<1>(last_flow)){
            adj[get<2>(last_flow)].push_back(get<2>(*i));
            adj[get<2>(*i)].push_back(get<2>(last_flow));
        }
        last_flow = *i;
    }
    long long cnt=0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<(cnt+2-1)/2;
}

/*
324 545
320 563
*/

/*
179 317
178 303
173 314
*/