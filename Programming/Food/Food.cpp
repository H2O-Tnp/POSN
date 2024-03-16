#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> food;
    vector<int> no;
    for(int i=0;i<m;i++){
        int in;
        cin>>in;
        no.push_back(in);
    }

    for(int i=1;i<=n;i++) food.push_back(i);
    do{
        bool yes = true;
        for(auto j:no){
            if(food[0]==j){
                yes = false;
                break;
            }
        }
        if(yes){
            for(auto i:food) printf("%d ",i);
            printf("\n");
        }
    }
    while(next_permutation(food.begin(),food.end()));
}