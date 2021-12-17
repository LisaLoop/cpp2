#include <iostream>
#include "Rectangle.h"
#include "Square.h"
using namespace std;

// Call the Rectangle constructor with both args = side.
Square::Square(int side) : Rectangle(side,side){};
 
// Call Rectangle::setWidth(w) then set height to width.
void Square::setWidth(int w)
{
    Rectangle::setWidth(w);
    Rectangle::setHeight(w);
}; 
// Just call setWidth(h)
void Square::setHeight(int h)
{
    setWidth(h);
}; 
// Call Rectangle::getType() then append "/Square".
std::string Square::getType() const
{
    return Rectangle::getType() + "/Square";
}; 