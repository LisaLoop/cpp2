#include <iostream>

class Shape
{
    private:
        static int shapeCount; // Initialize shapeCount to 0 in Shape.cpp.

    protected:
        int width, height; // Both width and height must always be >= 2.
        int ID;            // Set ID to ++shapeCount in the the constructor init list.
    public:
        Shape(int w = 2, int h = 2) // Set width and height via setters.
        {
            this->width = w;
            this->height = h;
        }

    void printInformation() const // See the sample output as a guide.
    {
    }

    int getWidth() const // Just return width.
    {
        return this->width;
    }
    int getHeight() const // Just return height.
    {
        return this->height;
    }
    void draw() const // This is a pure virtual method.
    {
        // nothing here
    }
    void setWidth(int w) // The width must be at least 2.
    {
        this->width = w;
    }
    void setHeight(int h) // The height must be at least 2.
    {
        this->height = h;
    }
    double getArea() const // Approximated by bounding rectangle = width*height
    {
        return this->width * this->height;
    }
    virtual double getPerimeter() const // Another pure virtual method.
    {
        return this->width + this->width + this->height + this->height;
    }
    virtual std::string getType() const // Just return "Shape".
    {
        return "Shape";
    }
};