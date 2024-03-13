#include <bits/stdc++.h>
using namespace std;

class Triangle{
    private: 
        double height = 1.0;
        double base = 1.0;
        string color = "black";
    public:
        Triangle(double height, double width, string color);
        Triangle(double height, double width);
        Triangle(double side);
        Triangle(string color);
        Triangle();

        double getHeight(){return height;}
        double getWidth(){return base;}
        string getColor(){return color;}
        double getArea(){return height*base;}
        double getPerimeter(){return 2*(height+base);}
        void setHeight(double h){height = h;}
        void setWidth(double w){base = w;}
        void setSide(double s){side = s;}
        void setColor(string c){color = c;}
        bool isSimilar(Triangle r);
};
Triangle::Triangle(double h, double w, string c){
    height = h;
    base = w;
    color = c;
}
Triangle::Triangle(double h, double w){
    height = h;
    base = w;
}
Triangle::Triangle(double s){
    base = s;
}
Triangle::Triangle(string c){
    color = c;
}

bool Triangle::isSimilar(Triangle r){
    if( (height == r.getHeight() || height == r.getWidth())
        && (base == r.getWidth() || base == r.getHeight())
        && color == r.color){
        return true;
    }else{
        return false;
    }
}

int main(){
    Triangle r1(2,3,"Green");
    Triangle r2(2,3,"Green");
    Triangle r11(2,3,"Yellow");

    cout<<r1.isSimilar(r11);
}