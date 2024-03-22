#include <bits/stdc++.h>
using namespace std;


vector<int> order;

int main(){
    int n;
    cin>>n;
    while(n--){
        string cmd;
        cin>>cmd;
        int arr[6+1] = {0,1,2,3,5,4,6};
        int tem[7] = {0,0,0,0,0,0,0};
        for(int i=0;i<cmd.size();i++){
            switch (cmd[i]) {
            case 'F':
                tem[1]=arr[4];
                tem[2]=arr[1];
                tem[3]=arr[3];
                tem[4]=arr[6];
                tem[5]=arr[5];
                tem[6]=arr[2];
                break;
            case 'B':
                tem[1]=arr[2];
                tem[2]=arr[6];
                tem[3]=arr[3];
                tem[4]=arr[1];
                tem[5]=arr[5];
                tem[6]=arr[4];
                break;
            case 'L':
                tem[1]=arr[5];
                tem[2]=arr[2];
                tem[3]=arr[1];
                tem[4]=arr[4];
                tem[5]=arr[6];
                tem[6]=arr[3];
                break;
            case 'R':
                tem[1]=arr[3];
                tem[2]=arr[2];
                tem[3]=arr[6];
                tem[4]=arr[4];
                tem[5]=arr[1];
                tem[6]=arr[5];
                break;
            case 'C':
                tem[1]=arr[1];
                tem[2]=arr[5];
                tem[3]=arr[2];
                tem[4]=arr[3];
                tem[5]=arr[4];
                tem[6]=arr[6];
                break;
            case 'D':
                tem[1]=arr[1];
                tem[2]=arr[3];
                tem[3]=arr[4];
                tem[4]=arr[5];
                tem[5]=arr[2];
                tem[6]=arr[6];
                break;
            }
            for(int j=1;j<=6;j++){
                arr[j]=tem[j];
            }
            // for(auto j:arr){
            //     cout<<j<<' ';
            // } cout<<endl;
        }
        order.push_back(arr[2]);
    }
    for(auto i:order){
        cout<<i<<' ';
    } cout<<endl;
}