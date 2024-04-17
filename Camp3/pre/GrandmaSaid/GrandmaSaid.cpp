#include <bits/stdc++.h>
using namespace std;

vector<long long> sumsubs(vector<long long> &arr){ // @param : ans
    vector<long long> sumsub;
    int maxs = 2<<arr.size()-1;
    int comp = 2<<arr.size()-2;

    for(int bit=3;bit<maxs;bit++){
        if(bit%2==0) continue;
        int sum = 0;
        for(int s=0;s<arr.size();s++){
            if((comp>>s) & bit){
                sum+=arr[s];
            }
        }
        sumsub.emplace_back(sum);
    }
    return sumsub;
}

int main(){
    int Q;
    cin>>Q;
    while(Q--){
        vector<long long> a;
        vector<long long> ans;
        int N;
        cin>>N;

        int mln = pow(2,N);
        for(int i=0;i<mln;i++){
            int in;
            cin>>in;
            a.emplace_back(in);
        }
        sort(a.begin(),a.end());
        ans.emplace_back(a.at(1));

        for(int i=2;i<mln-1;i++){
            if(a[i]==-1) continue;
            ans.emplace_back(a.at(i));
            if(ans.size() == N) break;
            int num = a.at(i);
            int k=i+1;

            vector<long long> c = sumsubs(ans);
            sort(c.begin(),c.end());
            
            for(auto it:c){
                while(it!=a[k]) k++;
                a[k]=-1;
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
        cout<<"\n";
    }
}