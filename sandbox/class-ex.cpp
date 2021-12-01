//
// class-ex.cpp
//
// Keith Mehl  Oct. 11, 2000
// CSCI-15 example program
// Introduce classes with a simple example.
// modified 2/22/18 to change min to minute to avoid an STL label
// modified 3/9/16 to clean code up a bit
// Modified 3/7/16 to show allowed changes per C++ 2011 standard
//

#include <iostream>
#include <iomanip>
using namespace std;

// first a plain struct schema (declaration) TIME1
struct TIME1
{
    int hour;   // 2011 C++: you may default in class definition, e.g. = 0;
    int minute; // = 0; But, if you do, you MAY NOT initialize at declaration!
    int sec;    // = 0;
};

// now define a class TIME2
#define MILITARY 1   // for time display format
#define NORMAL   2
class TIME2  // class declaration (I have heard this called a schema)
{
private:// only class functions (methods) can access private members
    int hour;  // whether those members are data or other methods
    int minute;
    int sec;
public:      // any client code can use public data or method
            // method declarations or prototypes
    TIME2();  // default constructor, time 0, 0, 0
    TIME2( int h, int m, int s ); // normal constructor
    void setTime( int h, int m, int s ); // set to time if legal, else 0:0:0
    void printTime( int mode );  // print time in MILITARY or NORMAL style
    void increment( void );   // add one second to time, "wrapping" if needed
};
// the following functions can only modify an object of type TIME2
// default constructor, set time 0, 0, 0
// this is a method definition
// Note: constructors cannot have a return type - they do not "return"
// like an ordinary function/method: you do not "call" them!
// TIME2() is a member of class TIME2 (analogous to namespace)
TIME2::TIME2( void )  // :: is the "scope resolution operator"
{
    hour = minute = sec = 0;
    cout << "I'm in the default constructor now\n" << flush;
    // constructors CANNOT return!
    // In 2011 standard, apparently return; is allowed but ignored
    // However, constructors still cannot return a value
}
// constructor, set time if it is legal, else 0's
TIME2::TIME2( int h, int m, int s )
{
    setTime( h, m, s );
    cout << "I'm in the normal constructor now\n" << flush;
}
// set time to an outside time, if time is legal
void TIME2::setTime( int h, int m, int s )
{
    // -> operator, LHS is pointer to struct or class object
    //              RHS is field or method in the struct or object
    this->hour = ( h >= 0 && h <= 23 ) ? h : 0;
    // (*ptr).field is equivalent to ptr->field; -> is MUCH more common
    (*this).minute  = ( m >= 0 && m <= 59 ) ? m : 0;
    // for member variables, you don't need to use "this", it's the default
    sec  = ( s >= 0 && s <= 59 ) ? s : 0;
    return;
}
// print time in MILITARY or NORMAL format
void TIME2::printTime( int mode )
{
    switch( mode )
    {
    case MILITARY :
        cout << setw(2) << setfill('0') << hour << ':'
             << setw(2) << setfill('0') << minute << ':'
             << setw(2) << setfill('0') << sec;
        break;
    case NORMAL   :
        cout << (hour == 0 || hour == 12 ? 12 : hour % 12) << ':'
             << setw(2) << setfill('0') << minute << ':'
             << setw(2) << setfill('0') << sec << ' '
    // both results of ?: must be the same type, here C-strings
             << (hour >= 12 ? "PM" : "AM") << flush;
        break;
    default       :
        cout << hour << ':' << minute << ':' << sec;   // unspecified format
    }
    return;
}
// add one second to time in "self"
void TIME2::increment( void )
{
    sec++;
    if( sec > 59 )
    {
        sec = 0;
        minute++;
        if( minute > 59 )
        {
            minute = 0;
            hour++;
            if( hour > 23 )
            {
                hour = 0;
            }
        }
    }
}
// print times (called from main() -- a function to avoid some duplicate code)
void printTimes( TIME1 time1, TIME2 time2 )
{
    cout << "time1 is " << time1.hour << ' '
         << time1.minute << ' ' << time1.sec << endl;
    cout << "time2 military ";
    time2.printTime( MILITARY );
    cout << endl << "time2 normal   ";
    time2.printTime( NORMAL );
    cout << endl;
    return;
}
// and some code to drive it all...
int main( void )
{
    TIME1 t1 = { 0, 0, 0 }; // initialize struct to 0:0:0
    TIME2 t2( 10, 30, 0 );  // use normal constructor to set t2 to 10:30:00
    TIME2 t3;               // default constructor sets t3 to 0:0:0
    // Pre-2011 C++, you could not use an initializer on a class object
    // this is not true any more! It changed in the 2011 C++ standard.
    // In 2011 C++ you can use initializers like you can
    // with scalars or arrays.  See Cplusplus.com for how to do it
    cout << "printing times t1 and t2" << endl;
    printTimes( t1, t2 );
    cout << "printing times t1 and t3" << endl;
    printTimes( t1, t3 );
    // set t1 and t2 to illegal times
    t1.hour = 25;
    t1.minute  = -2;
    t1.sec  = 65;
    t2.setTime( 25, -2, 65 );
    cout << "printing illegal times" << endl;
    printTimes( t1, t2 );
    // set t2 to OK time
    t2.setTime( 10, 59, 58 );
    printTimes( t1, t2 );
    // advance time in t2
    t2.increment();
    printTimes( t1, t2 );
    // assign one class object to another (copies object's data fields only)
    t3 = t2;
    t3.increment();
    t3.increment();
    cout << "After incrementing t3 twice\n";
    t3.printTime( MILITARY );
    cout << "\nt2 is still\n";
    t2.printTime( MILITARY );
    cout << endl;
    return 0;
}