#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    cout<<-1;
}

/*
x != 1
x == 0
x > 2^y
x = 0, y = n
2^y != 1
2^y != 1

x == 2^y

y = 1 : 1
y = 2 : 3
y = 3 : 7
        15

/*
7 6 5 4 3 2 1 0 y=3
7 6 5 4 0 1 2 3 y=2
6 7             y=1
    4 5         y=1
            3 2 y=1


*/