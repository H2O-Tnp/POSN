#include <iostream>
using namespace std;

int n,m;

int col(int y, int x, int fld[][1000]){
    int r = 0;
    int d = 0;
    if(y==n) return 0;
    if(x==m) return 0;
    /*
    3 4
    0 1 0 *
    0 1 0 *
    0 0 1 *
    * * *
    */
    r = col(y+1,x,fld);
    d = col(y,x+1,fld);
    if(r>d){
        // cout<<y<<" "<<x<<" "<<fld[y][x][0]+r<<endl;
        return fld[y][x]+r;
    }
    else{
        // cout<<y<<" "<<x<<" "<<fld[y][x][0]+d<<endl;
        return fld[y][x]+d;
    }
}

int main(){
    // input
    cin>>n>>m;
    int field[n][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>field[i][j];
        }
    }
    cout<<col(0,0,field)<<endl;
}

