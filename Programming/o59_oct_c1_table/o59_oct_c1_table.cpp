#include <bits/stdc++.h>
using namespace std;

int row[305];
int col[5005];
int minrow[305];


int main(){
    int R,C,M;
    cin>>R>>C>>M;
    int minv=INT_MAX;
    while(M--){
        int k;
        cin>>k;
        if(k==1){
            int r,c,x;
            cin>>r>>c>>x;
            minrow[r]=min(minrow[r],x);
            col[c]=x;
            row[r]=-1;
        }
        else if(k==2){
            int r,x;
            cin>>r>>x;
            row[r]=x;
            minrow[r]=x;
        }
        else if(k==3){
            int r,c;
            cin>>r>>c;
            if(row[r]==-1){
                cout<<col[c];
            }
            else{
                cout<<row[r];
            }
            cout<<"\n";
        }
        else if(k==4){
            int ans=INT_MAX;
            for(int i=1;i<R;i++){
                ans = min(ans,minrow[i]);
            }
            cout<<ans;
            cout<<"\n";
        }
    }
}
/*
3 3 14

3 1 2
4
2 1 100
2 2 10
2 3 40
4
1 2 1 50
1 2 3 200
4
1 3 3 25
3 3 2
4
1 2 2 60
4
*/