#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

void selectSort(vector<int>&vec,int th){
    for(int src=0;src<th;src++){
        int Maxidx = src;
        for(int tar=src+1;tar<vec.size();tar++){
            if(vec.at(tar)>vec.at(Maxidx)){
                Maxidx = tar;
            }
        }
        swap(vec.at(src),vec.at(Maxidx));
    }
}

void insertionSort(vector<int>& vec){
    for(int i=1;i<vec.size();i++){
        for(int j=i-1;j>=0;j--){
            if(vec.at(j)<vec.at(j+1)){
                swap(vec.at(j),vec.at(j+1));
            }
        }
        printVector(vec);
    }
}

int main(){
    int n,in;
    cin>>n;
    vector<int> num;
    while(n--){
        cin>>in;
        num.push_back(in);
    }
    int th;
    cin>>th;
    selectSort(num,th);
    cout<<num[th-1];
}

/*
10
9 5 12 65 42 13 28 1 99 4
4

5
1 4 3 3 2
3

*/