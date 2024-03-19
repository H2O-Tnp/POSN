#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> mat(10);
    for(int i=1;i<=9;i++){
        mat[i].push_back(0);
        for(int j=1;j<=9;j++){
            int in;
            cin>>in;
            mat[i].push_back(in);
        }
    }
    int n;
    cin>>n;
    while(n--){
        unordered_map<int,int> same(500);
        set<int> res;
        int mode,key;
        cin>>mode>>key;
        bool noSame = true;
        if(mode==-1){
            for(int c=1;c<=9;c++){
                same[mat[key][c]]++;
                int num = same[mat[key][c]];
                if(num==2){
                    res.insert(mat[key][c]);
                    noSame = false;
                }
            }
        }
        else if(mode==1){
            for(int r=1;r<=9;r++){
                same[mat[r][key]]++;
                int num = same[mat[r][key]];
                if(num==2){
                    res.insert(mat[r][key]);
                    noSame = false;
                }
            }
        }
        else{
            int row = ((key-1)/3 *3)+1;
            int col = ((key-1)%3 *3)+1;
            for(int r=row;r<=row+2;r++){
                for(int c=col;c<=col+2;c++){
                    same[mat[r][c]]++;
                    int num = same[mat[r][c]];
                    if(num==2){
                        res.insert(mat[r][c]);
                        noSame = false;
                    }
                }
            }
        }
        if(noSame) cout<<0;
        for(auto i:res) cout<<i<<' ';
        cout<<endl;
    }
}