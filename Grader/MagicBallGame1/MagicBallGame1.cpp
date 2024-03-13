#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int team = 1;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i]=0;
    }
    // for(auto j:arr){
    //     cout<<j<<' ';
    // }cout<<endl;

    for(int i=0; i<2*m; i++){
        int pos;
        cin>>pos;
        
        if(team != arr[pos-1]){
            arr[pos-1]=team;
        }
        
        if(team == 1) team = 2;
        else team = 1;
        // for(auto j:arr){
        //     cout<<j<<' ';
        // }cout<<endl;
    }
    int tran=0;
    int black=0;
    int white=0;
    for(int i = 0; i < n; i++){
        switch (arr[i])
        {
        case 0:
            tran++;
            break;
        case 1:
            black++;
            break;
        case 2:
            white++;
            break;
        }
    }
    cout<<tran<<' '<<black<<' '<<white<<endl;
}