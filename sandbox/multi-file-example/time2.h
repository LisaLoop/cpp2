//
// time2.h
// Keith Mehl
// 2/26/03
// Multi-file project example.
//
// define the class TIME2 schema
//
#ifndef TIME2_H_INCLUDED // prevent multiple inclusions
#define TIME2_H_INCLUDED

#define MILITARY 1   // for time display
#define NORMAL   2
class TIME2
{
private:     // only class functions can modify private members (data)
   int hour;
   int minute;
   int sec;
public:      // any client code can use a public member (functions, or methods)
   TIME2();  // default constructor, time 0, 0, 0
   TIME2( int h, int m, int s ); // normal constructor
   void setTime( int h, int m, int s ); // set to time given if legal
   void printTime( int mode );  // print time in MILITARY or NORMAL style
   void increment( void );   // add one second to time, "wrapping" at midnight
};

#endif // #ifndef TIME2_H_INCLUDED
