#include <bits/stdc++.h>
using namespace std;

struct Date
{
    /* data */
    int day;
    int month;
    int year;
};

bool compare(const Date &d1,const Date &d2){
    if(d1.year < d2.year){
        return true;
    }
    if(d1.year == d2.year && d1.month < d2.month){
        return true;
    }
    if(d1.year == d2.year && d1.month == d2.month && d1.day < d2.day){
        return true;
    }
    return false;
}


int main(){
    int n;
    cin>>n;
    struct Date date[n];
    int num=n;
    for(int i=0;i<n;i++)
    {
        /* code */
        cin>>date[i].day>>date[i].month>>date[i].year;
    }
    sort(date,date+num,compare);
    for(auto i:date){
        cout<<i.day<<' '<<i.month<<' '<<i.year;
        cout<<endl;
    }
}

/*
5
5 1 2545
6 2 1579
12 1 2410
1 12 2555
30 3 2565
*/