#include <bits/stdc++.h>
using namespace std;

long arr[3036];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        int N;
        cin>>N;
        if(N==0) break;
        for(int i=1;i<=N;i++){
            cin>>arr[i];
        }

        long ans=0;
        for(int i=1;i<=N;i++){
            if(arr[i]==arr[i-1]){
                continue;
            }
            int cntwid=1;
            for(int j=i+1;j<=N;j++){
                if(arr[j]>=arr[i]){
                    cntwid++;
                }
                else{
                    break;
                }
            }
            for(int j=i-1;j>=1;j--){
                if(arr[j]>=arr[i]){
                    cntwid++;
                }
                else{
                    break;
                }
            }
            // cout<<cntwid<<"\n";
            long test = cntwid*arr[i];
            if(ans < test){
                ans = test;
            }
            // cout<<i<<' '<<tj<<"\n";
        }
        printf("%ld\n",ans);
    }
}

/*
4 800 1000 1000 1000

7
2 1 1 5 1 3 3
*/