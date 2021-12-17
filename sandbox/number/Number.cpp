#include "Number.h"

ostream& operator<< (ostream& out, const Number& num) {
    out << num.n;
    return out;
}

Number::Number(int n) {
    setValue(n);
}
int Number::getValue() const {
    return this->n;
}
void Number::setValue(int n) {
    this->n = n;
  //  (*this).n = n;
}
Number& Number::operator++() {
    ++(this->n);
    return *this;
}
Number Number::operator++(int dummy) {
    Number temp = *this;
    ++(*this);  // call preincrement from postincrement
    return temp;
}


Number Number::operator+(const Number& other) const
{
    Number temp = *this;
    temp += other;
  //  Number temp(this->n + other.n);
    return temp;
}

Number& Number::operator+=(const Number& other) {
    this->n += other.n;
    return *this;
}
   

bool Number::operator<(const Number& other) const {
    return this->n < other.n;
}