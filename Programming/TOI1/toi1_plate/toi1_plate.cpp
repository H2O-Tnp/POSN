#include <bits/stdc++.h>
using namespace std;

struct Stu{
    int cls;
    int id;
};


Stu stu[10005];

void print(list<Stu> q){
    for(auto i:q){
        cout<<i.cls<<' ';
    }cout<<endl;
    for(auto i:q){
        cout<<i.id<<' ';
    }cout<<endl;
}

int main(){
    int c,s;
    cin>>c>>s;
    list<Stu> q;
    for(int i=1;i<=s;i++){
        cin>>stu[i].cls>>stu[i].id;
    }
    char in;
    do{
        cin>>in;
        if(in=='E'){
            int inID;
            cin>>inID;
            for(auto i:stu){
                if(i.id==inID){
                    int l=0;
                    bool hf=false;
                    for(auto j:q){
                        l++;
                        if(i.cls==j.cls){
                            hf=true;
                            auto it=q.begin();
                            advance(it,l++);
                            q.insert(it,i);
                            // print(q);
                            break;
                        }
                    }
                    if(!hf){
                        q.emplace_back(i);
                        // print(q);
                    }
                    break;
                }
            }
        }
        else if(in=='D'){
            if(q.empty()){
                cout<<"empty"<<endl;
            }
            else{
                cout<<q.front().id<<endl;
                q.pop_front();
            }
            // print(q);
        }
    } while(in!='X');
    cout<<0;
}