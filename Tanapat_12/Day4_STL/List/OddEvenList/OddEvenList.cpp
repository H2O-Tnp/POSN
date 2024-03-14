#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> ran,even,odd;
    int n;
    srand(time(0));
    n = rand()%21;
    if(n<10){
        n+=10;
    }

    cout<<"--- Random Numbers ["<<n<<"] ---\n";
    while(n--){
        int num = rand()%101;
        ran.push_front(num);
        cout<<num<<' ';
        if(num%2==0) even.push_front(num);
        else odd.push_front(num);
    }
    cout<<"\n--- Even Linked List ["<<even.size()<<"] ---\n";
    for(auto i:even){
        cout<<i<<' ';
    }
    cout<<"\n--- Odd Linked List ["<<odd.size()<<"] ---\n";
    for(auto i:odd){
        cout<<i<<' ';
    }
    cout<<endl;
    while(true){
        if(even.empty()){
            cout<<"===> Even is the winner!";
            break;
        }
        if(odd.empty()){
            cout<<"===> Odd is the winner!";
            break;
        }
        if(even.front()>odd.front()) even.pop_front();
        else odd.pop_front();
    }
}