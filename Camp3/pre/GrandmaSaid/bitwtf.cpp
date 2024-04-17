#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {20,30,40};
    int maxs = 2<<arr.size()-1;
    int comp = 2<<arr.size()-2;

    for(int bit=1;bit<maxs;bit++){
        // s = array index
        int sum = 0;
        for(int s=0;s<arr.size();s++){
            // cerr<<"bit "<<bit<<"\n";
            // cerr<<"shift "<<(comp>>s)<<"\n";
            // cerr<<"and "<<((comp>>s) && bit)<<"\n";
            if((comp>>s) & bit){
                // cerr<<"Yes\n";
                cerr<<arr[s]<<"\n";
                sum+=arr[s];
            } else {
                // cerr<<"No\n";
            }
        }
        cerr<<"sum "<<sum<<"\n";
        // cerr<<"\n";
        // break;
    }

}

/*

2^size - 1
*/