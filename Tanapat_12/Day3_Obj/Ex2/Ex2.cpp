#include <bits/stdc++.h>
using namespace std;
class Triangle
{
private:
    double height = 1.0;
    double base = 1.0;
    string color = "black";
    bool equal = false;

public:
    // con
    Triangle(double b, double h, string str);
    Triangle(double b, double h);
    Triangle(double side, string str);
    Triangle(double side);
    Triangle(string col) { color = col; }
    Triangle();

    // getter
    double getHeight() { return height; }
    double getBase() { return base; }
    string getColor() { return color; }
    double getArea() { return 0.5 * base * height; }
    double getPerimeter();

    // setter
    void setH(double x) { height = x; }
    void setB(double x) { base = x; }
    void setColor(string str) { color = str; }

    // Check
    bool isEquilateral();
    bool iscolor(string str);
    bool isSameColor(Triangle &t);
    bool isBigger(Triangle &t);
    bool isSmaller(Triangle &t);

    void copyFrom(Triangle &t);
};
Triangle::Triangle(double b, double h, string str)
{
    base = b;
    height = h;
    color = str;
}
Triangle::Triangle(double b, double h)
{
    base = b;
    height = h;
};
Triangle::Triangle(double side, string str)
{
    base = side;
    height = sqrt(3) * 0.5 * side;
    color = str;
};
Triangle::Triangle(double side)
{
    base = side;
    height = sqrt(3) * 0.5 * side;
};
double Triangle::getPerimeter()
{
    if (isEquilateral() == true)
        return base * 3;
    else
        return 0.0;
}
bool Triangle::isEquilateral()
{
    if (height / base == sqrt(3) / 2)
        return true;
    else
        return false;
}
bool Triangle::iscolor(string str)
{
    if (color == str)
        return true;
    else
        return false;
}
bool Triangle::isSameColor(Triangle &t)
{
    if (color == t.getColor())
        return true;
    else
        return false;
}
bool Triangle::isBigger(Triangle &t)
{
    if (getArea() > t.getArea())
        return true;
    else
        return false;
}
bool Triangle::isSmaller(Triangle &t)
{
    if (getArea() < t.getArea())
        return true;
    else
        return false;
}
void Triangle::copyFrom(Triangle &t)
{
    height = t.getHeight();
    base = t.getBase();
    color = t.getColor();
}

int main()
{
    Triangle T1(1,2,"Red");
    Triangle T2(2,3,"Blue");
    cout<<T2.isSmaller(T1);

}