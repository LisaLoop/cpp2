#include <iostream>
#include <string>
using namespace std;

class Dots
{
    friend ostream &operator<<(ostream &out, const Dots &d)
    {
        d.print(out);
        return out;
    }

public:
    Dots(int n = 0);             // constructor
    string get() const;          // return s
    void set(int n);             // set s to n dots or the empty string if n < 0
    Dots operator++(int dummy);  // postincrement (add one more dot)
    Dots &operator++();          // preincrement (add one more dot)
    Dots &operator*=(int k);     // multiply # of dots by k, when k >=0
    Dots operator*(int k) const; // like *=,  but don't modify *this.
    void print(ostream &out, bool endline = false) const;
    // output s and possibly an endl
private:
    string s;
};