#include<iostream>
#include<cmath>
#include "Shape.h"
using namespace std;

class Triangle: public Shape {
    protected:
        int width, height; // Both width and height must always be >= 2.
    public: 
    // Call Shape constructor and ensure width >= 3, height >= 2
    Triangle(int w = 3, int h = 2)
    // Triangle(int w, int h)
    {
        if(w < 3){
            cout << "width must be greater than or equal to 3" << endl;
            return;
        }
        if(h < 2){
            cout << "height must be greater than or equal to 2" << endl;
            return;
        }
        this->width = w;
        this->height = h;
    }
    void setWidth(int w)  // Ensure that width >= 3
    {
         if(w < 3){
            cout << "width must be greater than or equal to 3" << endl;
            return;
        }
        this->width = w;

    } 
    void draw() const // See the sample output as a guide
    {
        cout << "I'm drawing a triangle" << endl;
    }  
    double getArea() const // Call Shape::getArea() then divide by 2.
    {
        return this->Shape::getArea() / 2.0;
    }  
    double getPerimeter() const // Use the Pythagorean theorem.
    {
        return this->width + this->height + sqrt((this->width * this->width) + (this->height * this->height)); 
    } 
    std::string getType() const // Call Shape::getType() then append "/Triangle"
    {
        return this->Shape::getType() + "/Triangle";
    }
};