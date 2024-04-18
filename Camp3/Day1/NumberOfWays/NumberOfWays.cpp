#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e5+5;
int arr[MAX_N];
int qs[MAX_N];


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    qs[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        qs[i]=qs[i-1]+arr[i];
    }

    if(qs[n]%3==0){
        
    } else {
        cout<<0<<"\n";
    }
    
}

/*
5
1 2 3 0 3

4
0 1 -1 0

2
4 1

10
2 5 -2 2 -3 -2 3 5 -5 -2


*/