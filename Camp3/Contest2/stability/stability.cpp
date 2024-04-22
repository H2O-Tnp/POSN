#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int sum =0;
    int arr[N+1][M+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
            sum+=arr[i][j];
        }

    }
    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j] < sum/(N*M)){
                cnt++;
            }
        }
    }
    // cout<<(N*M)-cnt<<"\n";
    int test = sum/(N*M);
    cout<<((N*M)-cnt+1)*test<<"\n";
}

/*
2 7 2
15 6 5 12 1 7 9
17 2 15 5 2 4 17
48
stability (2 of 3)
ตัวอย่างที 3
ข้อมูลนําเข้า ข้อมูลส่งออก
3 3 0
2 0 1
2 2 2
1 2 3

*/