#include <iostream>
using namespace std;

int fib(int n, int m[]){
    if(n<=2) return 1;
    m[n] = fib(n-1, m) + fib(n-2, m);
    return m[n];
}

int main(){
    int in;
    cin>>in;
    
    int mem[in]={0};
    cout<<fib(in,mem);

    return 0;
}