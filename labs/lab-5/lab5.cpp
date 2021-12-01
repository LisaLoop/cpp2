
// a) Overload the stream insertion operator as a friend function.
// Output the Point object in the format (x,y) e.g. (3.4,5.6).
// Here is a template for you to fill in:

ostream & operator<< (ostream & out, const Point & p)

{

 out << '(' << p.x << ',' << p.y << ')';

}

 

// b) Overload preincrement (Add 1 to x and add 1 to y, return the updated current object.)
// Here is a template for you to fill in:
Point & Point::operator++()

{
    ++this.x;
    ++this.y;
    return this;
}

 


// c) Overload post-increment. (Add 1 to x and add 1 to y,
// return a copy of the original object before increment.)

Point  Point::operator++(int dummy)

{
 Point copy = new Point(this.x, this.y);
 this.x++;
 this.y++;
 return copy;
 
}