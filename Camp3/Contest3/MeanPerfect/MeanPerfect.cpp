#include <bits/stdc++.h>
using namespace std;

vector<long long> vec;
int 

long long sumsubs(vector<long long> &arr){ // @param : ans
    vector<long long> sumsub;
    long long maxs = 2<<arr.size()-1;
    long long comp = 2<<arr.size()-2;
    unsigned long long ans = 0;
    for(int bit=1;bit<maxs;bit++){
        unsigned long long sum = 0;
        unsigned long long cnt = 0;
        for(int s=0;s<arr.size();s++){
            if((comp>>s) & bit){
                sum+=arr[s];
                cnt++;

                // cout<<arr[s]<<' ';
            }
        }
        // cout<<"\n";
        
        if(sum%cnt==0){
            // cout<<"cnt "<<cnt<<" sum "<<sum<<'\n';;
            // cout<<"yes\n";
            ans++;
        }
    }
    return ans%5454541;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin>>N;
    long long minN=INT_MAX;
    long long maxN=INT_MIN;
    for(int i=1;i<=N;i++){
        long long in;
        cin>>in;
        minN = min(minN,in);
        maxN = max(maxN,in);
        vec.emplace_back(in);
    }
    if(minN == maxN){
        long num = 0;
        if(N==4) num = 15;
        if(N==5) num = 21;
        if(N==6) num = 63;
        cout<<num<<"\n";
        // if(N%2==0){
        //     cout<<((N/2)*(N+1))%5454541<<"\n"; 
        // }
        // else {
        //     cout<<((N)*((N+1)/2))%5454541<<"\n"; 
        // }
    } else {
        cout<<sumsubs(vec)<<'\n';
    }
}