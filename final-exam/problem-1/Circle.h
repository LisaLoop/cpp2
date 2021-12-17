/*
a) Implement a Circle class for our Shape hierarchy.
Circle should be a derived class from Shape.
Of course, the width and height must be equal as for a square.
( Geometrically, that's the diameter of the circle. )
We will also enforce width and height >= 6.
Override the appropriate methods including
getArea(),
getPerimeter(),
setHeight(), setWidth(),
getType() and draw().
Make sure your draw function draws a realistic circle, at least
if we were to use a font with aspect ratio of 1  (like Raster 8 x 8).   
*/
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <string>
class Circle : public Shape
{
    public: 
        Circle(int diameter = 6);
        double getArea() const;
        double getPerimeter() const;
        void setHeight(int h);
        void setWidth(int w);
        std::string getType() const;
        void draw() const;
};
#endif