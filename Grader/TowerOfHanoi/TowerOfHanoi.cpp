#include <bits/stdc++.h>
using namespace std;

void toh(int n, string &st, string &en, string &br){
    if(n>0){
        toh(n-1,st,br,en);
        cout<<st<<" => "<<en<<'\n';
        toh(n-1,br,en,st);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    string instr[3];
    cin>>instr[0]>>instr[1]>>instr[2];
    toh(n,instr[0],instr[2],instr[1]);
}