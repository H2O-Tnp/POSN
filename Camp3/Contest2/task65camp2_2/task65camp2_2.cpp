#include <bits/stdc++.h>
using namespace std;

bool arr[10005];
int qs[10005];


int main(){
    long long N,Q;
    cin>>N>>Q;
    
    for(int i=1;i<=N;i++){
        arr[i]=true;
    }
    int kee=3;
    for(int k=0;k<=10000;k+=2){
        if(kee+k > N) continue;
        for(int i=3;i<=N;i++){
            if(i%(kee+k)==0){
                arr[i]=!arr[i];
            }
        }
    }

    qs[0]=0;
    for(int i=1;i<=N;i++){
        qs[i]=qs[i-1]+arr[i];
    }

    while(Q--){
        int l,r;
        cin>>l>>r;
        cout<<qs[r]-qs[l-1]<<"\n";
    }
        
}

/*
N^2
2N^2
*/