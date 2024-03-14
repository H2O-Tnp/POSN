#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
        string name;
        int score;
    public:
        Student(string name, int score){
            this->name = name;
            this->score = score;
        }
        Student();
        string getName(){ return name; }
        int getScore(){ return score; }
};

string aboveAvg(stack<Student> clss,int avg){
    string res;
    while(clss.size() != 0){
        if(clss.top().getScore() > avg){
            res += clss.top().getName() + " ";
        }
        // cout<<clss.front().getName()<<endl;
        clss.pop();
    }
    return res;
}

int findAvg(stack<Student> clss){
    int avg=0;
    int n = clss.size();
    while(clss.size() >0){
        avg += clss.top().getScore();
        clss.pop();
    }
    avg/=n;
    return avg;
}

int main()
{
    Student std1("Nam",80),std2("Lin",45),std3("Papang",90);
    stack<Student> Classroom;
    Classroom.push(std1);
    Classroom.push(std2);
    Classroom.push(std3);

    cout<<"above average\n"<<aboveAvg(Classroom,findAvg(Classroom))<<endl;
    // c/out<<Classroom.front().getName();

}