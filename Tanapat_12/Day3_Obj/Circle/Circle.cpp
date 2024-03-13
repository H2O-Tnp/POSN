#include <bits/stdc++.h>
using namespace std;

class Circle{
    private:
        double radius = 1.0;
        string color = "black";
    public:
        Circle(double r, string color);
        Circle(string color);
        Circle();

        void setRadius(double r){radius = r;}
        void setColor(string c){color = c;}

        double getRadius(){return radius;}
        string getColor(){return color;}
        double getDiameter() { return radius *2; }
        double getArea() { return M_PI*radius*radius; }
        double getCircumference() { return 2*M_PI*radius; }

        bool isSimilar(Circle r);
};
Circle::Circle(double r, string c){
    radius = r;
    color = c;
}
Circle::Circle(string c){
    color = c;
}
bool Circle::isSimilar(Circle c){
    if(radius == c.radius && color == c.color){
        return true;
    }else{
        return false;
    }
}

int main(){
    Circle r1(2,"Green");
    Circle r2(2,"Green");
    Circle r3(2,"Yellow");

    if(r1.isSimilar(r3)) cout<<"True";
    else cout<<"False";
}