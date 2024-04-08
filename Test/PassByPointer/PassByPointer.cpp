#include <iostream>
using namespace std;

void pbp(int *ptr){
    *ptr = 4;
}

int main(){
    int a = 5;
    pbp(&a);
    cout<<a;
}