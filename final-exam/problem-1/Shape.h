#ifndef SHAPE_H
#define SHAPE_H

#include<iostream>
#include <string>
using namespace std;
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
    Shape& operator*=(int k);
    Shape& operator++();
};
ostream & operator<< (ostream & out, const Shape & s);

/*
Shape& operator*=(int k) ;
The job of operator*= is to multiply both width and height of the current object by k, assuming k > 0,
and return a reference to the updated current object.
(Recall we did something similar with operator++() ,
where the we increased width and height by 1.)   Note: there is a special case where k is 0 or negative.
In this situation we will leave the current object unchanged, since multiplying width and height by 0 or
a negative number would result in illegal values.
*/
Shape& Shape::operator*=(int k)
{
    this->width *= k;
    this->height *= k;
    return *this;
}
/*
// c) Overload post-increment. (Add 1 to x and add 1 to y,
// return a copy of the original object before increment.)
*/
Shape& Shape::operator++()
{
 this->width++;
 this->height++;
 return *this;
}

/*
a) Implement operator*= as it would appear in Shape.cpp.
*/
ostream& operator<< (ostream & out, const Shape * p)

{
 out << '(' << p->getWidth() << ',' << p->getHeight() << ')';
 return out;

}

// b) Overload preincrement (Add 1 to x and add 1 to y, return the updated current object.)
// Here is a template for you to fill in:
// Point & Point::operator++()

// {
//     ++this.x;
//     ++this.y;
//     return this;
// }

#endif
