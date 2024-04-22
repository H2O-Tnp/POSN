#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; //menu
    cin>>N;
    int M;
    cin>>M;
    int Q;
    cin>>Q;
    vector<int> qs(N+1);
    qs[0]=0;

    long long sum = 0, test = 0;
    map <long long, int> cnt;
    cnt[M] = 1;
    for(int i=1;i<=N;i++){
        int in;
        cin>>in;
        qs[i] = qs[i-1]+in;


        sum += in;
        // test += qs(r)
        test += cnt[sum];
        // qs(r)++
        cnt[sum + M]++;
    }

    // cout<<"test "<<test<<"\n";

    while(Q--){
        int l,r;
        cin>>l>>r;
        if(test<=0){
            cout<<"No\n";
            continue;
        }
        for(int i=l;i<=r;i++){
            for(int j=i;j<=r;j++){
                // cout<<qs[j]-qs[i-1]<<"\n";
                if(qs[j]-qs[i-1]==M){
                    cout<<"Yes\n";
                    // test--;
                    j=r+5;
                    i=r+5;
                    r=0;
                }
            }
        }
        if(r!=0){
            cout<<"No\n";
        }
        
        // cout<<"sum "<<qs[r]-qs[l-1]<<"\n";
    }
}