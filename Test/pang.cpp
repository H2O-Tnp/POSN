#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    double height = 1.0;
    double width = 1.0;
    string color = "black";

public:
    Rectangle(double a, double b, string c)
    {
        height = a;
        width = b;
        color = c;
    }
    Rectangle(double a, double b)
    {
        height = a;
        width = b;
    }
    Rectangle(double side)
    {
        width = side;
        height = side;
    }
    Rectangle(string color)
    {
        this->color = color;
    }
    Rectangle()
    {
    }
    void setHeight(double height)
    {
        this->height = height;
    }
    void setWidth(double width)
    {
        this->width = width;
    }
    void setColor(string color)
    {
        this->color = color;
    }
    void setSide(double side)
    {
        width = side;
        height = side;
    }
    bool isSimilar(Rectangle a)
    {
        if (color == a.getColor() && ((height == a.getHeight() || height == a.getWidth()) && (width == a.getHeight() || width == a.getWidth())))
            return 1;
        return 0;
    }
    string getColor()
    {
        return color;
    }
    double getWidth()
    {
        return width;
    }
    double getHeight()
    {
        return height;
    }
    double getArea()
    {
        return width * height;
    }
    double getPerimeter()
    {
        return 2 * width + 2 * height;
    }
};

int main()
{
    Rectangle a, b;
    a.setHeight(5);
    a.setWidth(4);
    b.setHeight(4);
    b.setWidth(5);
    cout<<a.getColor()<<' '<<a.getHeight()<<' '<<a.getWidth()<<endl;
    cout<<b.getColor()<<' '<<b.getHeight()<<' '<<b.getWidth()<<endl;

    if (a.isSimilar(b))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}