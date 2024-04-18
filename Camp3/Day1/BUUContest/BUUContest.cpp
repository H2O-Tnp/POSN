#include <bits/stdc++.h>
using namespace std;

int D,K;

priority_queue<int> pq;

int main(){
    cin>>D>>K;
    
    long long ans=0;
    for(int i=1;i<=D;i++){
        int N,B;
        cin>>N>>B;
        while(N--){
            int P;
            cin>>P;
            pq.emplace(P-((i-1)*K));
        }
        while(B--){
            ans += pq.top()+((i-1)*K);
            pq.pop();
        }
    }
    cout<<ans<<"\n";
}

/*
3 10
5 2
8 4 5 1 10
4 3
14 4 9 14
2 1
20 7
*/