#include <iostream>
#include "Circle.h"
#include "Sphere.h"
using namespace std;
Sphere::Sphere(int diameter) : Circle(diameter){};
double Sphere::getArea() const
{
    double PI = 3.14159;
    double diameter = getWidth();
    double radius = (diameter / 2);
    double area = 4 * PI * (radius * radius);
    return area;
};
double Sphere::getVolume() const
{
    double PI = 3.14159;
    double diameter = getWidth();
    double radius = (diameter / 2);
    double volume = (4.0 / 3) * PI * (radius * radius * radius);
    return volume;
};
std::string Sphere::getType() const
{
    return Circle::getType() + "/Sphere";
};