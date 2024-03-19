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
        Student* next=nullptr;
};

int main(){
    int N=5;
    Student* start = nullptr;
    Student* last = nullptr;
    
    for(int i=N;i>=0;i--){
        // Insert data
        Student* newStudent = new Student(i+1, -1);

        // Head
        if(i==N){
            start = newStudent;
            last = newStudent;
        }
        else if(newStudent->score < start->score){
            newStudent->next = start;
            start = newStudent;
        } else {
            Student* prev = start;
            Student* current = start->next;
            while(current!=nullptr){
                if(newStudent->score < current->score){
                    prev->next = newStudent;
                    newStudent->next = current;
                    break;
                } else {
                    prev = current;
                    current = current->next; 
                }
            }
            if(current==nullptr){
                last->next = newStudent;
                last = newStudent;
            }
        }
    }

    Student* current = start;
    while(current!=nullptr){
        printf("%d ",current->score);
        current = current->next;
    }
}