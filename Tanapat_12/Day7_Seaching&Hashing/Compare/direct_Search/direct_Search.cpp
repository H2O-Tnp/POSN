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
};

int main(){
    int N;
    cin>>N;
    vector<Student> value(N);
    for(auto& v:value){
        cin>>v.score>>v.year;
    }

    auto sorter = [] (Student const& s1, Student const& s2) -> bool
    {
        if(s1.score == s2.score){
            return s1.year < s2.year;
        }
        else{
            return s1.score > s2.score;
        }
    };
    
    sort(value.begin(),value.end(),sorter);
    for(auto v:value){
        cout<<v.score<<' '<<v.year<<endl;
    }
}