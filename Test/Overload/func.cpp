#include <bits/stdc++.h>
using namespace std;

int add(int a,int b){
    return a+b;
}
int add(int a,int b,int c){
    return a+b+c;
}

double add(double a,double b){
    return a+b;
}

int main(){
    cout<<add(5,6);
    cout<<"\n";
    cout<<add(5.4,6.7);
    cout<<"\n";
    cout<<add(1,2,3);
}