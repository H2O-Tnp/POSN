#include <bits/stdc++.h>
using namespace std;

int sub(vector<vector<int>> &image){
    int n = image.size();
    bool all = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(image[i][j]!=image[0][0]){
                all = false;
                break;
            }
        }
        if(!all){
            break;
        }
    }
    if(all){
        return 2;
    }

    int len = 1;
    for(int i=0;i<n;i+=(n/2)){
        for(int j=0;j<n;j+=(n/2)){
            vector<vector<int>> subImage(n/2,vector<int>(n/2));
            for(int k=0;k<n/2;k++){
                for(int l=0;l<n/2;l++){
                    subImage[k][l] = image[k+i][l+j];
                }
            }
            len += sub(subImage);
        }
    }
    return len;
}


int main(){
    int l;
    cin>>l;
    vector<vector<int>> image(l,vector<int>(l));
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            cin>>image[i][j];
        }
    }
    cout<<sub(image);
}