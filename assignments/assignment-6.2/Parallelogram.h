#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H


#include "Shape.h"


class Parallelogram : public Shape
{
    // For a Parallelogram we require both width and height >= 2. (Same as for a Shape.)

private:
    int topShift; // Must be >= 0. This represents the offset of the top relative to the bottom.
                  // For example, if topShift == height then interior angles are 135 and 45 degrees.
                  // If topShift == 0, then the interior angles are both 90 degrees (a rectangle).

public:
    Parallelogram(int w = 2, int h = 2, int topShift = 0); // call Shape Constructor & call setTopShift()

    void draw() const;  // See the sample output as a guide.

    double getPerimeter() const;  // Use the Pythagorean theorem.

    void setTopShift(int t);      // topShift must be nonnegative

    std::string getType() const;  // call Shape::getType() and append "/Parallelogram".

};
#endif
