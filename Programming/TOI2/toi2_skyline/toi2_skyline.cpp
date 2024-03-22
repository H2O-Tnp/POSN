#include <bits/stdc++.h>
using namespace std;

struct Sky{
    int h=0;
};



int main(){
    Sky sky[3000];
    int n;
    cin>>n;
    int maxen = 0;
    while(n--){
        int in;
        int st,he,en;
        cin>>st>>he>>en;
        maxen = max(maxen,en);
        for(int i=st;i<en;i++){
            sky[i].h=max(sky[i].h,he);
        }
    }
    // for(int i=0;i<=maxen;i++){
    //     cout<<i<<" "<<sky[i].h<<endl;
    // }
    for(int i=1;i<=maxen+1;i++){
        if(sky[i].h != sky[i-1].h){
            cout<<i<<' '<<sky[i].h<<' ';
        }
    }
}