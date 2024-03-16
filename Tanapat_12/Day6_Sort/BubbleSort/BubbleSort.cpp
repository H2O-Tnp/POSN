#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

void Bubble(vector<int> &vec){
    for(int i=vec.size()-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(vec.at(j)>vec.at(j+1)){
                swap(vec.at(j),vec.at(j+1));
            }
            printVector(vec);
        }
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
    Bubble(num);
}

/*
5
5 4 3 1 2
*/