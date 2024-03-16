#include <bits/stdc++.h>
using namespace std;
int n;

struct Student{
    string name;
    string sur;
    int score;
};

bool compare(Student &s1,Student &s2){
    if(s1.score > s2.score){
        return true;
    }
    if(s1.score == s2.score && s1.name < s2.name){
        return true;
    }
    if(s1.score == s2.score && s1.name == s2.name && s1.sur < s2.sur){
        return true;
    }
    return false;
}

int main(){
    cin>>n;
    struct Student arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].name>>arr[i].sur>>arr[i].score;
    }
    sort(arr,arr+n,compare);
    for(auto i:arr){
        cout<<i.name<<' '<<i.sur<<' '<<i.score<<endl;
    }
}