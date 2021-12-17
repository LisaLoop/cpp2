#include<iostream>
#include<cstring>
/*
In a class C, a pure virtual method is declared like this:

virtual void f() = 0;

That means there is no implementation for f() within C.
The function exists purely (ahem..) for the purpose of dynamic binding.
For example the draw() is a pure virtual method in Shape and is overridden
in Rectangle, Triangle and so on. The benefit is that we can call draw()
from each element of the shapePointers array and get the correct output
relative to whatever the object type is. This is literally polymorphism
("having many forms"): A pointer of the base class type can exhibit as
many different forms as there are derived classes with overridden versions
of draw().

 

When a class contains one or more pure virtual methods,
it's called an abstract class. We cannot create objects of
the class type. We can only create object of derived classes
that override (i.e. implement) the pure virtual methods of the base class.
If a derived class fails to override some of the pure virtual methods,
then it too is an abstract class.  The assumption is that a classes
further down in the chain of inheritance will eventually supply
implementations for all the pure virtual methods of the original base class.
*/
class ExampleShape
{
    public:
        ExampleShape();
        virtual string getType() = 0;
};

class X
{
    public: 
        virtual char getA() = 0;
        virtual char getB() = 0;
}

class Y : public X
{
    public:
        virtual char getB();
}

class Z : public Y 
{
    public: 
        virtual char getA();
}