#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

void insertionSort(vector<int>& vec){
    for(int i=1;i<vec.size();i++){
        for(int j=i-1;j>=0;j--){
            if(vec.at(j)>vec.at(j+1)){
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
    insertionSort(num);
}

/*
5
4 7 1 3 2

*/