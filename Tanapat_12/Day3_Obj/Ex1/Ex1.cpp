#include <bits/stdc++.h>
using namespace std;

class Rectangle{
    private:
        double height = 1.0;
        double width = 1.0;
        string color = "black";
        double side;
    public:
        Rectangle(double height, double width, string color);
        Rectangle(double height, double width);
        Rectangle(double side);
        Rectangle(string color);
        Rectangle();

        double getHeight(){return height;}
        double getWidth(){return width;}
        string getColor(){return color;}
        double getArea(){return height*width;}
        double getPerimeter(){return 2*(height+width);}
        void setHeight(double h){height = h;}
        void setWidth(double w){width = w;}
        void setSide(double s){side = s;}
        void setColor(string c){color = c;}
        bool isSimilar(Rectangle r);
};
Rectangle::Rectangle(double h, double w, string c){
    height = h;
    width = w;
    color = c;
}
Rectangle::Rectangle(double h, double w){
    height = h;
    width = w;
}
Rectangle::Rectangle(double s){
    side = s;
}
Rectangle::Rectangle(string c){
    color = c;
}

bool Rectangle::isSimilar(Rectangle r){
    if(height == r.height && width == r.width && color == r.color){
        return true;
    }else{
        return false;
    }
}

int main(){
    Rectangle r1(2,3,"Green");
    Rectangle r2(2,3,"Green");
    Rectangle r11(2,3,"Yellow");

    cout<<r1.isSimilar(r11);
}