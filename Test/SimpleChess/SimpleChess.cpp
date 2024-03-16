#include <bits/stdc++.h>
using namespace std;

struct Chess
{
    int x=-1;
    int y=-1;
};

struct Chess chess[6];

bool isChess(int i, int j){
    for(int c=1;c<=5;c++){
        if(chess[c].x==j && chess[c].y==i){
            cout<<c<<' ';
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int c,x,y;
        cin>>c>>x>>y;
        chess[c].x=x;
        chess[c].y=y;
    }
    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++){
            if(!isChess(i,j)) cout<<0<<' ';
        }
        cout<<endl;
    }
}