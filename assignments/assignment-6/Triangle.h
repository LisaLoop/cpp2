#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "Shape.h"


class Triangle : public Shape
{
    // For a Triangle we require width >= 3 and height >= 2
public:
    Triangle(int w = 3, int h = 2);  // Call Shape constructor and ensure width >= 3
    void setWidth(int w);  // Ensure that width >= 3
    void draw() const;  // See the sample output as a guide
    double getArea() const;  // Call Shape::getArea() then divide by 2.
    double getPerimeter() const; // Use the Pythagorean theorem.
    std::string getType() const; // Call Shape::getType() then append "/Triangle"
};
#endif
