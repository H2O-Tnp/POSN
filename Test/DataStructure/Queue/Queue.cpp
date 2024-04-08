#include <iostream>
#include <queue>
using namespace std;

int main(){
    int arr[8] = {1,2,3,4,5,6,7,8};
    queue<int> q1;
    for(int i:arr) q1.push(i);
    auto it = q1.front();
    while(!q1.empty()){
        cout<<q1.front()<<endl;
        q1.pop();
    }
        
}