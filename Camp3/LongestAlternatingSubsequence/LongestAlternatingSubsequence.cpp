#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt1 = 1;
    int cnt2 = 1;
    bool great = true;
    bool less = true;
    // vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    // vector<int> nums = {3,1,2,4};
    
    for(int i=1;i<nums.size();i++){
        if(great && nums[i] > nums[i-1]){
            cnt1++;
            great =! great;
        }
        else if(!great && nums[i] < nums[i-1]){
            cnt1++;
            great =! great;
        }
        // 
        if(less && nums[i] < nums[i-1]){
            cnt2++;
            less =! less;
        }
        else if(!less && nums[i] > nums[i-1]){
            cnt2++;
            less =! less;
        }
    }
    cout<<max(cnt1,cnt2)<<"\n";
}

// 1 17 5 10 13 15 10 5 16 8