#ifndef NUMBER_H
#define NUMBER_H

#include <istream>
#include <ostream>
#include <string>

using namespace std;

class Number
{
    friend ostream& operator<< (ostream& out, const Number& num);
private:
    int n;

public:
    Number(int n = 0);

    int getValue() const;
    void setValue(int n);

    // Number add(const Number& other);
    Number& operator++();
    Number operator++(int dummy);
    Number operator+(const Number& other) const;
    Number& operator+=(const Number& other);
    bool operator<(const Number& other) const;
};

#endif