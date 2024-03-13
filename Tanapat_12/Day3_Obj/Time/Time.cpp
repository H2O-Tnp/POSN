#include <bits/stdc++.h>
using namespace std;

class Time{
    private:
        int hour, minute, second;

    public:
        Time();
        Time(int h, int m, int s);
        void printTime();
        void setTime(int h, int m, int s);
        int getHour() { return hour; }
        int getMinute() { return minute; }
        int getSecond() { return second; }
        void setHour(int h) { hour = h; }
        void setMinute(int m) { minute = m; }
        void setSecond(int s) { second = s; }
        string diff(Time t);
};
Time::Time(){
    hour = minute = second = 0;
}
Time::Time(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}
void Time::setTime(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}
string twoDigit(int t){
    if (t < 10)
        return "0" + to_string(t);
    else
        return to_string(t);
}
void Time::printTime() {
    cout<<"The time : ("
    <<twoDigit(hour)<<":"<<twoDigit(minute)
    <<":"<<twoDigit(second)<<")"<<endl;
}
string Time::diff(Time t){
    int durT1 = hour*3600 + minute*60 + second;
    int durT2 = t.hour*3600 + t.minute*60 + t.second;
    int diffT = abs(durT1-durT2);
    
    int h = diffT/3600;
    diffT -= h*3600;
    
    int m = diffT/60;
    diffT -= m*60;

    int s = diffT;

    return "D   time : (" + twoDigit(h) + ":" + twoDigit(m)
           + ":" + twoDigit(s) + ")";
}

int main(){
    Time t1(3, 55, 54);
    // Time t1(5, 5, 5);
    t1.printTime();

    Time t2(7, 17, 43);
    t2.printTime();
    cout<<t1.diff(t2);
}

// 4:38:11
// 4: