#include <bits/stdc++.h>
using namespace std;

double land[4][4];
bool visited[4][4];

int main(){
    int r,c;
    cin>>r>>c;
    int minP = INT_MAX;
    int min_i=0;
    int min_j=0;

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%lf",&land[i][j]);
            if(land[i][j]<minP){
                minP = land[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }
    double tCost=0;
    
    int ad_r[8]={0,1,0,-1,1,-1,-1,1};
    int ad_c[8]={1,0,-1,0,1,-1,1,-1};
    visited[min_i][min_j]=true;
    queue<pair<int,int>> q;
    q.emplace(min_i,min_j);
    while(!q.empty()){
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout<<land[i][j]<<' ';
            }
            cout<<endl;
        }

        auto [cur_r,cur_c] = q.front();
        cout<<cur_r<<' '<<cur_c<<endl;
        q.pop();
        tCost+=land[cur_r][cur_c];
        cout<<"cost "<<tCost<<endl;

        double maxCost=0;
        for(int i=0;i<8;i++){
            int added_r = cur_r+ad_r[i];
            int added_c = cur_c+ad_c[i];
            if(added_r == 0 || added_c == 0 || added_r>r || added_c>c){
                continue;
            }
            maxCost = max(maxCost,land[added_r][added_c]);
            land[added_r][added_c]+=(land[cur_r][cur_c]*0.10);
            if(!visited[added_r][added_c]){
                min_i = min(min_i,added_r);
                min_j = min(min_j,added_c);
                
                
            }
            q.emplace(min_i,min_j);
            visited[min_i][min_j]=true;
        }
    }
    printf("%.2lf",tCost);
    cout<<tCost;
}