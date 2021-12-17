// Inheritance1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Triangle.h"
#include "Square.h"

/*
Calling a base class method
For example, in the Triangle class,  getType would call Shape::getType().
The Shape:: is needed otherwise the getType() method in Triangle would be calling itself.

To call a base class constructor  from a derived class constructor, use
the constructor initialization list. For example, the header for the constructor
in Triangle would look like this

Triangle::Triangle(int w, int h) : Shape(w,h) 

*/

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

    //b) Suppose r is a pointer of type Shape * and points to some object
    //of a derived class type.  Also suppose we've previous implemented the
    // stream insertion operator (outputs width and height in parentheses)
    // and the pre-increment operator (increments width and height by 1).
    //Type a line of code uses the *= operator to multiply the object by 5,
    //then uses the pre-increment operator to increment the object and finally
    // uses the << operator to output the object to the console. This should all
    // be done within one statement without using any other variables.
    // As an example, if initially the object's width is 10 and height 12 then
    // the new values for the  width and height would be 51 and 61, respectively
    // so the output would be (51,61).
    Shape* s = new Rectangle(10,12);
    // std::cout << (*s*=5);

    for (int i = 0; i < NUMSHAPES; i++) {
        print(*shapePointers[i]);
    }
    // for (int i = 0; i < NUMSHAPES; i++) {
    //     delete shapePointers[i];
    // }
 
    testSetters();
    cout << "BYE!" << endl;

    return 0;
}

   
  

