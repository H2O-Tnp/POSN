#include <bits/stdc++.h>
using namespace std;

//            key val
unordered_map<int,int> vote(5000000);// loadign factor = 1/5 = 0.2

int main(){
    int N,C,K,number,pt;
    scanf("%d %d",&N,&C);
    scanf("%d",&K);
    int point[C+1];
    // fill 0
    for(int i=1;i<=C;++i){
        point[i]=0;
    }
    while(N--){
        scanf("%d %d",&number,&pt);
        if(vote[number]<K){
            vote[number]++;
            if(pt<=C && pt>0){
                point[pt]++;
            }
        }
    }
    for(auto i:point) cout<<endl;
}