#include <iostream>
using namespace std;

void pbp(int &ref){
    ref = 4;
}

int main(){
    int a = 5;
    int *ptr = &a;
    *ptr=7;
    cout<<*ptr<<endl;

    int &ref = a;
    ref++;
    cout<<ref<<endl;
    
    // pbp(a);
}