#include <iostream>
#include <list>
#include <vector>

using namespace std;

// void t(list<int> argl){
//     auto it = argl.begin();
//     advance(it,5);
//     cout<<*it;
// }
vector<int> v1{1,2,3,4,5,6,7,8,9};

void LISTbisearch(list<int>::iterator it_f ,list<int>::iterator it_b, int tar){
    list<int>::iterator it_m = it_f;
    advance(it_m,distance(it_f,it_b)/2);
    cout<<*it_m<<" Dis:"<<distance(it_f,it_b)<<" "<<distance(it_f,it_b)/2<<" -";
    if(it_f==it_b){
        cout<<"Nope\n";
        return;
    }
    if(*it_m == tar){
        cout<<"Found\n"; 
        return;
    }
    
    if(*it_m > tar){
        // cout<<"Left\n";
        LISTbisearch(it_f, --it_m,tar);
    }
    else{
        // cout<<"Right\n";
        LISTbisearch(++it_m, it_b,tar);
    }
}

void Vecbisearch(int idf,int idb, int tar){
    int idm = (idf+idb)/2;
    cout<<v1[idm]<<" ";
    if(idf==idb){
        cout<<"Nope\n";
        return;
    }
    if(v1[idm] == tar){
        cout<<"Found\n"; 
        return;
    }
    
    if(v1[idm] > tar){
        // cout<<"Left\n";
        Vecbisearch(idf, idm,tar);
    }
    else{
        // cout<<"Right\n";
        Vecbisearch(idm, idb,tar);
    }
}

int main(){
    list<int> l1{1,2,3,4,5,6,7,8,9,10};
    //           0 1 2 3 4 5 6 7 8
    for(int i=1;i<11;i++){
        LISTbisearch(l1.begin(),l1.end(),i);

    }
    // Vecbisearch(0,v1.size(),6);
    return 0;
}

