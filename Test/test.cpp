#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Running\n";


    int arr[]={1,2,3};
    while(next_permutation(arr, arr+3)){
        for(int i=0; i<3; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
            
    }
    return 0;

}