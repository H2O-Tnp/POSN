#include <stdio.h>

int main(){
    int x,now=1,jump=6;
    scanf("%d",&x);
    while(true){
        if(x < now+jump){
            if(x==now+jump-1){
                now+=jump-1;
            }
            else if(x==now+jump-2){
                printf("Connot");
            }
            break;
        }
        now+=jump;
        jump+=8;
    }
    if(x!=now+jump-2){
        printf("%d", now);
    }
}