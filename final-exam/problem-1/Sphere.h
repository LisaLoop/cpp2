#ifndef SPHERE_H
#define SPHERE_H
#include "Circle.h"
#include <string>
class Sphere : public Circle
{
    public:
        Sphere(int diameter = 6);
        double getArea() const;
        double getVolume() const;
        std::string getType() const;
};
#endif