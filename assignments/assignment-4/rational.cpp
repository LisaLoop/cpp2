//
//  rational.cpp
//  assignment-4
//
//  Lisa Lehrman 
//  10/19/21
//  A program that attempts to meet the spec
//  to write a Rational number calculator 

#include "rational.h"

// default constructor
Rational::Rational() {
    this->num = 0;
    this->denom = 1;
}
// normal constructor
Rational::Rational(long num, long denom) {
    this->num = num;
    this->denom = denom;
}

Rational Rational::add(Rational augend) {
    return *this;
}

Rational Rational::multiply(Rational multiplicand) {
    return *this;
}

Rational Rational::subtract(Rational subtrahend) {
    return *this;
}

Rational Rational::divide(Rational dividend) {
    return *this;
}

long Rational::gcd(long denominator1, long denominator2) {
    long a = denominator1;
    long b = denominator2;
    long r = a % b;
    while( r != 0 )
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int Rational::read(std::ifstream &inputFile) {
    char c;
    inputFile >> c >> this->num >> c >> this->denom >> c;
    this->validate();
    return 1;
}

int Rational::write(std::ofstream &output) {
    output << "( " << this->num << " / " << this->denom << " )";
    return 1;
}

void Rational::validate() {
    if(this->denom == 0)
    {
        this->num = 0;
        this->denom = 1;
        cout << num << ' '<< denom << endl;
        cout << "Invalid rational format" << endl;
        return;
    }
    long result = this->gcd(this->num, this->denom);
    if(result != 1)
    {
        this->num /= result;
        this->denom /= result;
    }
    
}








