#ifndef SQUARE_H
#define SQUARE_H


#include "Rectangle.h"
#include <string>

class Square : public Rectangle
{
    // width and height must be >= 2 and equal to each other!
public:
    Square(int side = 2); // Call the Rectangle constructor with both args = side.

    void setWidth(int w);  // Call Rectangle::setWidth(w) then set height to width.

    void setHeight(int h); // Just call setWidth(h).

    std::string getType() const;  // Call Rectangle::getType() then append "/Square".

};
#endif
