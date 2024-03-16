#include <bits/stdc++.h>
using namespace std;

void printVector(const vector<int>& arr) {
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

void mergeSort(vector<int> &vec,int l , int r){
    if(l==r) return;
    int mid = (l+r)/2;
    mergeSort(vec,l,mid);
    mergeSort(vec,mid+1,r);

    vector<int> leftVec;
    vector<int> rightVec;
    for(int i=l;i<=mid;i++) leftVec.push_back(vec[i]);
    for(int j=mid+1;j<=r;j++) rightVec.push_back(vec[j]);

    int i=0,j=0,k=l;
    while(i < leftVec.size() && j < rightVec.size()){
        if(leftVec[i] < rightVec[j]){
            vec[k] = leftVec[i];
            i++; k++;
        }
        else{
            vec[k] = rightVec[j];
            j++; k++;
        }
    }
    while(i < leftVec.size()){
        vec[k] = leftVec[i];
        i++; k++;
    }
    while(j < rightVec.size()){
        vec[k] = rightVec[j];
        j++; k++;
    }
}

int main(){
    vector<int> arr = {6, 5, 3, 1, 8, 7, 2, 4};
    int n,in;
    cin>>n;
    vector<int> num;
    while(n--){
        cin>>in;
        num.push_back(in);
    }
    mergeSort(num,0,num.size()-1);
    printVector(num);
}

/*
5
5 4 3 1 2
*/