#include <iostream>
#include "Parallelogram.h"
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int w, int h) : Parallelogram(w,h,0){};

std::string Rectangle::getType() const
{
    return Parallelogram::getType() + "/Rectangle";
};
