#include <iostream>
using namespace std;

int fact(int n){
    if(n<2) return 1;
    return n*fact(n-1);
}

int main(){
    int in;
    cin>>in;
    cout<<fact(in);
    return 0;
}