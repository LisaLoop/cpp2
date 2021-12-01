//
//  rational.h
//  assignment-4
//
//  Created by Lisa Lehrman 
//  10/19/21
//  A program that attempts to meet the spec
//  to write a Rational number calculator 

#ifndef rational_h
#define rational_h

#include <iostream>
#include <fstream>
using namespace std;

class Rational
{
    private:
        long num;
        long denom;
        void validate();
        long gcd(long denominator1, long denominator2);
    public:
        Rational();  // default constructor
        Rational( long num, long denom ); // normal constructor
        Rational add(Rational augend);
        Rational multiply(Rational multiplicand);
        Rational subtract(Rational subtrahend);
        Rational divide(Rational dividend);
        int read(std::ifstream &input);
        int write(std::ofstream &output);
};


#endif /* rational */


