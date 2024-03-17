#include <vector>
#include <cstdio>

using namespace std;

int main(){
    int N;
    printf("Run 1\n");
    scanf("%d",&N);
    vector<int> value(N);
    for(auto& v:value){
        scanf("%d",&v);
    }
    for(auto v:value){
        printf("%d ",v);
    }
}