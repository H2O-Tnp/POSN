#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        int score;
        int year;
        Student() { score = -1; year = -1;}
        Student(int score,int year){
            this->score = score;
            this->year = year;
        }
        Student* next;
};

int main(){
    int N=5;
    Student* start = nullptr;
    Student* last = nullptr;
    

    for(int i=0;i<N;i++){
        // Insert data
        Student* s = new Student(i+1, -1);
        if(i==0){
            start = s;
        }
        else{
            last->next = s;
        }
            
        last = s;        
    }

    Student* current = start;
    while(current!=nullptr){
        printf("%d ",current->score);
        current = current->next;
    }
}