#include <bits/stdc++.h>
using namespace std;

const MAX_N = 64;

list<int> adj[MAX_N];
int data[MAX_N];

void addEdge(int src,int des){
    adj[src].push_back(des);
}

int rec(int st_r,int st_c,int en_r,int en_c){
    if(st_r == en_r) return 
    int mid = (r+c)/2;
    rec(mid+1 ,st_c ,en_r  ,mid);
    rec(st_r  ,st_c ,mid+1 ,mid);
    rec(mid+1 ,mid  ,en_r  ,en_c);
    rec(st_r  ,mid  ,mid   ,en_c);


}


int main(){
    int l;
    cin>>l;
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            int in;
            cin>>in;
            if(in==1){
                addEdge(i,j);
            }
        }
    }
}