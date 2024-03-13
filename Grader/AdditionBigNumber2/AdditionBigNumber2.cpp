#include <bits/stdc++.h>
using namespace std;
int na;
int nb;
int n;

void add(int base,int &ex, int arr[],deque<int> &a,deque<int> &b){
    if(base < 0){
        return;
    }
    arr[base] = (a[base] + b[base] + ex)%10;
    ex = (a[base] + b[base] + ex)/10;
    add(--base,ex,arr,a,b);
}

int main(){
    cin>>na;
    deque<int> a;
    for(int i=0; i<na; i++){
        cin>>a[i];
    }

    cin>>nb;
    deque<int> b;
    for(int i=0; i<nb; i++){
        cin>>b[i];
    }

    int diffn = abs(nb-na);
    if(na>nb){
        n = na;
        for(int i=0; i<diffn; i++){
            b.push_front(0);
        }
    }
    else{
        n = nb;
        for(int i=0; i<diffn; i++){
            a.push_front(0);
        }
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