#include <iostream>
#include "Shape.h"
#include "Triangle.h"
using namespace std;

// For a Triangle we require width >= 3 and height >= 2

// Call Shape constructor and ensure width >= 3

// Triangle::Triangle(int w, int h) : Shape(w,h)
Triangle::Triangle(int w, int h) : Shape(w, h)
{
    if (w < 3)
    {
        setWidth(3);
    }
};
// Ensure that width >= 3
void Triangle::setWidth(int w)
{
    if (w >= 3)
    {
        width = w;
    }
};

// See the sample output as a guide
void Triangle::draw() const
{
    for (int row = 0; row < height; row++)
    {
        int stars = (row + 1) * width / height;
        int spaces = (width - stars) / 2;
        for (int cols = 0; cols < spaces; cols++)
        {
            cout << ' ';
        }
        for (int cols = 0; cols < stars; cols++)
        {
            cout << '*';
        }
        for (int cols = 0; cols < spaces; cols++)
        {
            cout << ' ';
        }
        cout << endl;
    }
};
// Call Shape::getArea() then divide by 2.
double Triangle::getArea() const
{
    return Shape::getArea() / 2;
};
// Use the Pythagorean theorem.
double Triangle::getPerimeter() const
{
    double a = width / 2;
    double b = height;
    double cSqrd = (a * a) + (b * b);
    double c = sqrt(cSqrd);
    return 2 * (a + c);
};
// Call Shape::getType() then append "/Triangle"
std::string Triangle::getType() const
{
    return Shape::getType() + "/Triangle";
};