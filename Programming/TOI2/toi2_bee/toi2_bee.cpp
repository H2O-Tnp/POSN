/*
1 year
sol -> 1 work
work -> 1 w 1 s
fck and die

mom -> 1 work
never die

** start 1 mom 1 work
*/ 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int in=0;
    do{    
        cin>>in;
        int mom=1;
        int work=1;
        int last_work=work;
        int sol=0;
        int last_sol=sol;
        
        for(int i=1;i<=in;i++){
            work+=mom;
            work+=last_sol;
            work+=last_work;
            work-=last_work;
            sol+=last_work;
            sol-=last_sol;

            last_work = work;
            last_sol=sol;
        }
        cout<<work<<' '<<work+sol+mom<<endl;
    } while(in!=-1);
    
        

}