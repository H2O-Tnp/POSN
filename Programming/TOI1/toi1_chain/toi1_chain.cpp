#include <bits/stdc++.h>
using namespace std;

int main(){
    int l,w;
    cin>>l>>w;
    string word[w];
    for(int i=0;i<w;i++){
        cin>>word[i];
    }

    string last=word[0];
    for(int i=1;i<w;i++){
        int dif=0;
        for(int c=0;c<l;c++){
            if(word[i][c] != last[c]){
                dif++;
            }
        }
        if(dif>2){
            for(int c=0;c<l;c++){
                cout<<last[c];
            }
            return 0;
        }
        last=word[i];
    }
    for(int c=0;c<l;c++){
        cout<<last[c];
    }
}