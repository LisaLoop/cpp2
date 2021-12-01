//
// time2.cpp
// Keith Mehl
// 2/26/03
// CS15 multi-file project example.
// Implementation of the TIME2 class
// NOTE: DO NOT PUT THE CODE INTO A HEADER FILE!!!
//
#include <iostream> // this could go inside time2.h
using namespace std;
#include "time2.h"  // user-defined header in "" not <> (look "here" first)

// the following functions can only modify an object of type TIME2
// They are members of the class TIME2, or "methods"
// default constructor, set time 0, 0, 0
TIME2::TIME2( void )
{
   hour = minute = sec = 0;
}
// normal constructor, set time if it is legal
TIME2::TIME2( int h, int m, int s )
{
   setTime( h, m, s );
   cout << "I'm in the constructor now\n" << flush;
   // I could just do the work here, but why?  I did this work elsewhere.
   // hour = ( h >= 0 && h <= 23 ) ? h : 0;
   // minute  = ( m >= 0 && m <= 59 ) ? m : 0;
   // sec  = ( s >= 0 && s <= 59 ) ? s : 0;
}
// set time to an outside time, if time is legal
void TIME2::setTime( int h, int m, int s )
{
   hour = ( h >= 0 && h <= 23 ) ? h : 0;
   minute = ( m >= 0 && m <= 59 ) ? m : 0;
   sec  = ( s >= 0 && s <= 59 ) ? s : 0;
}
// print time in MILITARY or NORMAL format
void TIME2::printTime( int mode )
{
   switch( mode )
   {
       // notice, both results of ?: must be the same type, here C-strings
   case MILITARY : cout << ( hour < 10 ? "0" : "" ) << hour << ':'
                        << ( minute < 10 ? "0" : "" )  << minute << ':'
                        << ( sec < 10 ? "0" : "" )  << sec;
                   break;
   case NORMAL   : cout << ( hour == 0 || hour == 12 ? 12 : hour % 12) << ":"
                        << ( minute < 10 ? "0" : "" )  << minute << ':'
                        << ( sec < 10 ? "0" : "" )  << sec << ' '
                        << ( hour >= 12 ? "PM" : "AM" ) << flush;
                   break;
                      // unspecified format
   default       : cout << hour << ":" << minute << ":" << sec;
   }
   return;
}
// add one second to time
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
   return;
}