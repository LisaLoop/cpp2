#ifndef SHAPE_H
#define SHAPE_H

#include <string>


class Shape
{
private:
    static int shapeCount;  // Initialize shapeCount to 0 in Shape.cpp. 

protected:
    int width, height; // Both width and height must always be >= 2.
    const int ID;      // Set ID to ++shapeCount in the the constructor init list.

public:

    Shape(int w = 2, int h = 2);   // Set width and height via setters.

    void printInformation() const;  // See the sample output as a guide.

    int getWidth() const;  // Just return width.
    int getHeight() const; // Just return height.
    virtual void draw() const = 0;   // This is a pure virtual method. 
    virtual void setWidth(int w) ;   // The width must be at least 2.
    virtual void setHeight(int h) ;  // The height must be at least 2.
    virtual double getArea() const;  // Approximated by bounding rectangle = width*height
    virtual double getPerimeter() const = 0;  // Another pure virtual method.
    virtual std::string getType() const;  // Just return "Shape".


};

#endif
