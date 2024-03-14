#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> even,odd;
    int cnt=3;
    while(cnt){
        int n;
        cin>>n;
        if(n!=0){
            cnt = 3;
        }
        else{
            cnt--;
        }
        if(n%2==0) even.push_front(n);
        else odd.push_front(n);
    }
    even.pop_front();
    even.pop_front();
    even.pop_front();


    while(true){
        if(even.empty()){
            cout<<"EVEN "<<odd.size();
            break;
        }
        if(odd.empty()){
            cout<<"ODD "<<even.size();
            break;
        }
        if(even.front()>odd.front()) even.pop_front();
        else odd.pop_front();
    }
}