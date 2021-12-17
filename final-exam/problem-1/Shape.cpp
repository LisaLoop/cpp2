#include <iostream>
#include "Shape.h"
using namespace std;

int Shape::shapeCount = 0;
Shape::Shape(int w, int h) : ID(++shapeCount)
{
    setWidth(w);
    setHeight(h);
};

// Prints id, width, height, area, perimeter, type
void Shape::printInformation() const
{
    cout << "Id: " << ID << " width: " << getWidth() << " height: "
         << getHeight() << " area: " << getArea() << " perimeter: "
         << getPerimeter() << " type: " << getType() << endl;
};
// Just return the width
int Shape::getWidth() const
{
    return width;
};
// Just return height.
int Shape::getHeight() const
{
    return height;
}; 
// The width must be at least 2.
void Shape::setWidth(int w)
{
    if(w < 2){return;}
    width = w; 
};  
// The height must be at least 2.
void Shape::setHeight(int h)
{
    if(h < 2){return;}
    height = h;
};  
// Approximated by bounding rectangle = width*height
double Shape::getArea() const
{
    return width*height;
}; 
// Just return "Shape".
std::string Shape::getType() const
{
    return "Shape";
}; 
