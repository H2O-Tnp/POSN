#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6+5;

int arr[MAX_N];
int l[MAX_N];
int r[MAX_N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    //          i  num
    stack<pair<int,int>> stkl;
    stkl.emplace(1,l[1]);
    for(int i=2;i<=n;i++){
        while(!stkl.empty() && arr[i]>=arr[stkl.top().first]){
            l[i]++;
            l[i]+=stkl.top().second;
            stkl.pop();
        }
        stkl.emplace(i,l[i]);
    }
    stack<pair<int,int>> stkr;
    stkr.emplace(n,r[n]);
    for(int i=n-1;i>=1;i--){
        while(!stkr.empty() && arr[i]>=arr[stkr.top().first]){
            r[i]++;
            r[i]+=stkr.top().second;
            stkr.pop();
        }
        stkr.emplace(i,r[i]);
    }

    for(int i=1;i<=n;i++){
        cout<<l[i]+r[i]+1<<' ';
    }
}