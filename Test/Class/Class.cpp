#include <bits/stdc++.h>
using namespace std;

class person{
    private:
        int age;
        string name;
    public:
        person();
        person(int a){age = a;}
        person(int a, string n){age = a; name = n;}
        void setAge(int a) {age = a;}
        int getAge() {return age;}
        void setName(string n) {name = n;}
        string getName() {return name;}
};

int main(){
    person student(18,"Nam");
    cout<<student.getName()<<endl;
    person teacher(32);
    cout<<teacher.getAge()<<endl;
}