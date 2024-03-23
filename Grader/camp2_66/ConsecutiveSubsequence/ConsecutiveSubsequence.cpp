#include <bits/stdc++.h>
using namespace std;

int main(){
    string in;
    map<int,int> arr;
    // arr.emplace(-INT_MAX);
    while(true){
        cin>>in;
        if((in[0] >= 'a' && in[0] <= 'z') || (in[0] >= 'A' && in[0] <= 'Z')) break;
        int num=stoi(in);
        arr[num]=1;
    }

    auto it=arr.begin();
    auto maxst = it;
    auto maxen = it;
    auto st = maxst;
    auto en = maxen;
    it++;
    int maxcnt=0;
    while(it!=arr.end()){
        auto lastit=it; lastit--;
        if(it->first - lastit->first == 1){
            en=it;
        }
        else{
            if(maxen->first-maxst->first < en->first-st->first){
                maxen=en;
                maxst=st;
            }
            st=it;
        }
        it++;
    }
    maxen++;
    while(maxst!=maxen){
        cout<<maxst->first<<' ';
        maxst++;
    }
}