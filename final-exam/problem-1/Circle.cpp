#include <iostream>
#include "Shape.h"
#include "Circle.h"
using namespace std;
Circle::Circle(int diameter) : Shape(diameter, diameter)
{
    if (diameter < 6)
    {
        setWidth(6);
        setHeight(6);
    };
};
// the area of a circle is PI x the radius squared
double Circle::getArea() const
{
    double PI = 3.14159;
    double diameter = getWidth();
    double radius = (diameter / 2);
    double area = PI * (radius * radius);
    return area;
};
// C=2πr
double Circle::getPerimeter() const
{
    double PI = 3.14159;
    double diameter = getWidth();
    double radius = (diameter / 2);
    double circumference = 2 * PI * radius;
    return circumference;
};
void Circle::setHeight(int h)
{
    setWidth(h);
};
void Circle::setWidth(int w)
{
    if (w >= 6)
    {
        width = w;
    }
};
std::string Circle::getType() const
{
    return Shape::getType() + "/Circle";
};
void Circle::draw() const
{
    double PI = 3.14159;
    double diameter = getWidth();
    double radius = (diameter / 2);
    double cX = (diameter / 2);
    double cY = (diameter / 2);
    for (int row = 0; row < diameter; row++)
    {
        for (int col = 0; col < diameter; col++)
        {
            double pX = col;
            double pY = row;
            double lA = cX - pX;
            double lB = cY - pY;
            double c = sqrt((lA * lA) + (lB * lB));
            if (c <= radius)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
};