#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> vec(r+1,vector<int>(c+1));
    bool visited[r+1][c+1];
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            int input;
            cin>>input;
            vec[i][j]=input;
            visited[i][j]=false;
        }
    }
    int l;
    cin>>l;
    int ax[8] = {0, 1,-1,  0,-1, 1,1,-1};
    int ay[8] = {1, 0, 0, -1, 1,-1,1,-1};

    int n=0;
    vector<int> s;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(vec[i][j]<=l && !visited[i][j]){
                n++;
                int ns=1;
                queue<pair<int,int>> q;
                q.emplace(i,j);
                visited[i][j] = true;
                while(!q.empty()){
                    auto [y,x] = q.front();
                    q.pop();
                    for(int i=0;i<8;i++){
                        int addY=y+ay[i];
                        int addX=x+ax[i];
                        if((addY==0||addY==r+1||addX==0||addX==c+1)||visited[addY][addX]){
                            continue;
                        }
                        if(vec[addY][addX]>l){
                            continue;
                        }
                        q.emplace(addY,addX);
                        visited[addY][addX] = true;
                        ns++;
                    }
                }
                s.push_back(ns);
            }
        }
    }
    cout<<n<<"\n";
    sort(s.begin(),s.end());
    for(auto i:s){
        cout<<i<<"\n";
    }
}