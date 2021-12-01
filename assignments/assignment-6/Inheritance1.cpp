// Inheritance1.cpp : This file contains the 'main' function.
// Program execution begins and ends there.
//
/*
In a class C, a pure virtual method is declared like this:

virtual void f() = 0;

That means there is no implementation for f() within C.
The function exists purely (ahem..) for the purpose of dynamic binding. 
For example the draw() is a pure virtual method in Shape and is overridden in Rectangle,
Triangle and so on. The benefit is that we can call draw() from each element of the shapePointers
array and get the correct output relative to whatever the object type is.
This is literally polymorphism ("having many forms"): A pointer of the base
class type can exhibit as many different forms as there are derived classes
with overridden versions of draw().

 

When a class contains one or more pure virtual methods,
it's called an abstract class. We cannot create objects of the class
type. We can only create object of derived classes that override (i.e. implement)
the pure virtual methods of the base class. If a derived class fails to override
some of the pure virtual methods, then it too is an abstract class.
The assumption is that a classes further down in the chain of inheritance
will eventually supply implementations for all the pure virtual methods of the original base class.

*/

#include <iostream>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

void print(const Shape &s) {
    cout << endl;
    s.printInformation();
    cout << endl;
    s.draw();
    for (int i = 0; i < 100; i++) cout << '_';
    cout << endl;
}

void testSetters() {
  
    Parallelogram p;
    Rectangle r;
    Square s;
    Triangle t;
    cout << "t width is: " << t.getWidth() <<  "t height is: " << t.getHeight() << endl;
    Shape* shapePointers[] = { &p,&r,&s,&t };
    cout << endl << "Here are four default shapes." << endl << endl;
    for (int i = 0; i < 4; i++) {
        print(*shapePointers[i]);
    }
    Shape* sptr = nullptr;
    bool quit = false;
    do {
        cout << endl <<  "Enter 0 for parallelogram, 1 for rectangle, 2 for square, 3 for triangle, 4 to quit: ";
        int code;
        cin >> code;
        quit = code == 4;
        if (!quit) {
            Shape* sptr = shapePointers[code];
            cout << "What is the new width? ";
            int w;
            cin >> w;
            sptr->setWidth(w);
            print(*sptr);
            cout << "What is the new height? ";
            int h;
            cin >> h;
            sptr->setHeight(h);
            print(*sptr);
            if (sptr->getType() == "Shape/Parallelogram") {
                int t;
                cout << "What is the new topShift? ";
                cin >> t;
                ((Parallelogram*)sptr)->setTopShift(t);
                print(*sptr);
            }

        }
    } while (!quit);
}



int main()
{
    const int NUMSHAPES = 29;
    Shape* shapePointers[NUMSHAPES];
    
    shapePointers[0] = new Rectangle(20, 10);
    shapePointers[1] = new Rectangle(-1, -1);
    shapePointers[2] = new Rectangle(12, 38);
    shapePointers[3] = new Square(20);
    shapePointers[4] = new Square(50);
    shapePointers[5] = new Square(0);
    shapePointers[6] = new Triangle(0, 1);
    shapePointers[7] = new Triangle(2, 0);
    shapePointers[8] = new Triangle(20, 40);
    shapePointers[9] = new Triangle(50, 25);
    shapePointers[10] = new Triangle(24, 17);
    shapePointers[11] = new Triangle(11, 11);
    shapePointers[12] = new Triangle(40, 79);
    shapePointers[13] = new Triangle(79, 40);
    shapePointers[14] = new Triangle(95, 52);
    shapePointers[15] = new Triangle(21, 11);
    shapePointers[16] = new Triangle(11, 6);
    shapePointers[17] = new Triangle(39, 10);
    shapePointers[18] = new Triangle(13, 21);
    shapePointers[19] = new Parallelogram(79, 40, 20);
    shapePointers[20] = new Parallelogram(20, 17, 4);
    shapePointers[21] = new Parallelogram(65, 52, 11);
    shapePointers[22] = new Parallelogram(12, 12, 0);
    shapePointers[23] = new Parallelogram(12, 12, 6);
    shapePointers[24] = new Parallelogram(12, 12, 12);
    shapePointers[25] = new Parallelogram(12, 12, 18);
    shapePointers[26] = new Parallelogram(40, 64, 48);
    shapePointers[27] = new Parallelogram(20, 40, 60);
    shapePointers[28] = new Parallelogram(0, 0, -5);

    for (int i = 0; i < NUMSHAPES; i++) {
        print(*shapePointers[i]);
    }
    delete[] shapePointers;

    testSetters();
    cout << "BYE!" << endl;

    return 0;
}

   
  

