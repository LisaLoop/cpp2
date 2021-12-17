
/*
operator<< should return out.
operator++ should return *this rather than this.

copy shouldn't be dynamically allocated.
Otherwise there is a memory leak. Also new returns a pointer,
so there is a type mismatch. Use Point copy = *this;

*/
// a) Overload the stream insertion operator as a friend function.
// Output the Point object in the format (x,y) e.g. (3.4,5.6).
// Here is a template for you to fill in:

ostream & operator<< (ostream & out, const Shape & p)

{

 out << '(' << p.x << ',' << p.y << ')';

}

// b) Overload preincrement (Add 1 to x and add 1 to y, return the updated current object.)
// Here is a template for you to fill in:
Shape & Shape::operator++()

{
    ++this.x;
    ++this.y;
    return this;
}

 


// c) Overload post-increment. (Add 1 to x and add 1 to y,
// return a copy of the original object before increment.)
/*
person& operator=(const person& that)
{
    name = that.name;
    age = that.age;
    return *this;
}
*/
Shape&  Shape::operator++(int dummy)

{
 Shape copy = new Shape(this.x, this.y);
 this.x++;
 this.y++;
 return copy;
 
}