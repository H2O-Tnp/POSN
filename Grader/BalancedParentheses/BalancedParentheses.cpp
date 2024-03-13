#include <bits/stdc++.h>
using namespace std;

bool check(string in){
    stack<char>bal;

    for(int idin=0;idin<in.size();idin++){ // string travel
        if(in[idin]=='('){ // open
            bal.push('(');
        }
        else if(in[idin]==')'){ // close
            if(bal.empty()){
                return 0;
                idin = in.size();
            }
            else { // 
                bal.pop();
            }
        }
    }
    if(bal.empty()) return 1;
    else            return 0;
}

int main(){
    int n;
    cin>>n;
    string fr;
    string bc;
    string instr;
    fr.assign(n,'(');
    bc.assign(n,')');
    instr = fr+bc;
    sort(instr.begin(),instr.end());
    reverse(instr.begin(),instr.end());
    while(prev_permutation(instr.begin(),instr.end()))
    {
        if(check(instr)){
            cout<<instr<<endl;
        }
    }
    return 0;
}