#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "Parallelogram.h"

class Rectangle : public Parallelogram
{

public:
    Rectangle(int w = 2, int h = 2);
    void draw() const;

    void setWidth(int w);

    std::string getType() const;

};
#endif
