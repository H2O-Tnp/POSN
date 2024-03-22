/*
i v  x  l   c
1 5 10 50 100

1 10 < 3 ele
5 !=> 50
always >

< 400 {
    4 9 40 90 <
}

*/
#include <bits/stdc++.h>
using namespace std;

int rom[5]={1,5, 10,50, 100};
//          i v  x  l   c     
int memo[5]={1,0,0,0,0};

int main(){
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        if(i==1) continue;
        // cal rom
        int num=i;
        // cout<<"st: "<<num<<endl;
        while(num!=0){
            // cout<<num<<endl;
            if(num<4){
                memo[0]+=num;
                num=0;
            }
            else if(num==4){
                memo[0]++;
                memo[1]++;
                num=0;
            }
            else if(num==5){
                memo[1]++;
                num=0;
            }
            else if(num<9){
                memo[0]+=num-5;
                memo[1]++;
                num=0;
            }
            else if(num==9){
                memo[0]++;
                memo[2]++;
                num=0;
            }
            ////
            else if(num<40){
                memo[2]+=num/10;
                num=num%10;
            }
            else if(num<50){
                memo[2]++;
                memo[3]++;
                num=num%10;
            }
            else if(num==50){
                memo[2]++;
                memo[2]++;
                num=0;
            }
            else if(num<90){
                memo[2]+=num-50;
                memo[3]++;
                num=num%10;
            }
            else if(num==90){
                memo[2]++;
                memo[4]++;
                num=0;
            }
            else if(num<100){
                memo[2]++;
                memo[4]++;
                num=num%10;
            }
            else if(num<400){
                memo[4]+=num/100;
                num=num%100;
            }
            // else if(i<)
        }
    }
    for(auto i:memo){
        cout<<i<<' ';
    }
}