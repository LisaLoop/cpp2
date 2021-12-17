#include <iostream>
#include "Shape.h"
#include "Parallelogram.h"
using namespace std;

 // call Shape Constructor & call setTopShift()
Parallelogram::Parallelogram(int w, int h, int topShift)
: Shape(w, h)
{
    
    Parallelogram::setTopShift(topShift);
};

void Parallelogram::draw() const
{
    int totalImageWidth = (topShift + width);
    for(int row=0; row < height; row++)
    {
        int y = row + 1;
        int offset = (height - y) * topShift / height;
        int rightSpace = (offset + width);
        int rightSpaces = totalImageWidth - rightSpace;
        for(int col=0; col < offset; col++)
        {
            cout << ' ';
        }
        for(int col=0; col < width; col ++)
        {
            cout << '*';
        } 
         for(int col=0; col < rightSpaces; col++)
        {
            cout << ' ';
        }
        cout << endl;
    }
}; 
 // Use the Pythagorean theorem.
double Parallelogram::getPerimeter() const
{
    double a = topShift;
    double b = height;
    double cSqrd = (a*a) + (b*b);
    double c = sqrt(cSqrd);
    return 2 * (c + width);
};
// topShift must be nonnegative
void Parallelogram::setTopShift(int t)
{
    if(topShift >= 0){
        topShift = t;
    }
};
// call Shape::getType() and append "/Parallelogram".
std::string Parallelogram::getType() const
{
    return Shape::getType() + "/Parallelogram";
}; 