#include <bits/stdc++.h>
using namespace std;
int n;
void add(int base,int &ex, int arr[],int a[],int b[]){
    if(base < 0){
        return;
    }
    arr[base] = (a[base] + b[base] + ex)%10;
    ex = (a[base] + b[base] + ex)/10;
    add(--base,ex,arr,a,b);
}

int main(){
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cin>>n;
    int b[n];
    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    int res[n];
    int ex=0;

    add(n-1,ex,res,a,b);

    if(ex!=0){
        cout<<ex;
    }
    for(int i=0;i<n;i++){
        cout<<res[i];
    }
}