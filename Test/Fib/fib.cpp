#include <iostream>
using namespace std;

long long fib(int n, long long m[]){
    if(n<=2) return 1;
    if(m[n]!=-1) return m[n];
    m[n] = fib(n-1, m) + fib(n-2, m);
    return m[n];
}

int main(){
    int in;
    cin>>in;
    
    long long mem[in+1];
    for(int i=0; i<in+1; i++) mem[i]=-1;

    cout<<fib(in,mem);

    return 0;
}