#include <bits/stdc++.h>
using namespace std;

int n;
string add (string x, string y, int order, int inc){
    if(x.empty()) return "";
    int plus = (x[x.length()-1]-'0') + (y[y.length()-1]-'0') + inc;
    // cout<<x[x.length()-1]-'0'<<' '<<y[y.length()-1]-'0' << ' '<<plus<<endl;

    if(plus > 9) inc = plus/10;
    else inc = 0;

    return add(x.substr(0,x.length()-1),y.substr(0,x.length()-1),order,inc) + to_string(plus%10);
}

int main(){
    string x,y; 
    int n;
    char c;
    cin>>n;
    for(int i=0;i<n;i++){ 
        cin>>c;
        x+=c;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        y+=c;
    }
    
    if(x.length()>y.length()){
        int diff = x.length()-y.length();
        string ex(diff,'0');
        ex+=y;
        cout<<add(x,ex,0,0);
    }
    else{
        int diff = y.length()-x.length();
        string ex(diff,'0');
        ex+=x;
        cout<<add(ex,y,0,0);
    }
}