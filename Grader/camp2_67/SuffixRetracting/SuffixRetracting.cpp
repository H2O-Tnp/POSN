#include <bits/stdc++.h>
using namespace std;

void printV(vector<long long>& vec,int l){
    if(l==vec.size()) return;
    cout<<vec.at(l)<<' ';
    printV(vec,l+1);
}

int sum(vector<long long>& vec,int l,int r){
    if(l>r) return 0;
    int num = vec.at(r);
    vec.pop_back();
    return num + sum(vec,l,r-1);
}

void back(vector<long long>& vec,int& k,int l,int r){
    printV(vec,0);
    cout<<"\n";
    if(l <= 0){
        vec.push_back(sum(vec,0,r));
        printV(vec,0);
        return;
    }
    vec.push_back(sum(vec,l,r));
    back(vec,k,l-k,l);
}

int main(){
    vector<long long> A; //ตัวแปรสําหรับเก็บชุดตัวเลข
    int K;
    cin >> K;
    int input = 0;
    while (true){
        cin >> input;
        if (input == -1)
            break;
        else
            A.push_back(input);
    }
    back(A, K, A.size()-1-K, A.size()-1);
        cout<<"\n";

    return 0;
}

/*
2
4 6 5 7 3 7 2 4 1 7 -1
*/