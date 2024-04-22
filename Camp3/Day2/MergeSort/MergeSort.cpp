#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
int A[MAX_N];

void mergeSort(int l,int r){
    if (l==r) return;

    int mid = (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);

    vector<int> tmp(r-l+1);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid or j <= r){
        if(i == mid + 1) tmp[k++] = A[j++]; // i สุด
        else if(j == r + 1) tmp[k++] = A[i++]; // j สุด
        else if(A[i] <= A[j]) tmp[k++] = A[i++]; // i better than j
        else tmp[k++] = A[j++]; // j better than i
    }
    for(int i=0;i< r-l+1; i++){
        A[l+i] = tmp[i];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int N; cin>>N;

    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    mergeSort(1,N);

    for(int i=1;i<=N;i++){
        cout<<A[i]<<' ';
    }
    return 0;
}