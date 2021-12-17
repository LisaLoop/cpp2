#include <iostream>
#include "dots.h"
using namespace std;
// Implement the Dots class shown below that represents a string
// of zero or more dots. For example Dot d(4) would represent
// a string with four dots:  “….”
Dots::Dots(int n)
{
    set(n);
};

string Dots::get() const
{
    return s;
};
// set s to n dots or the empty string if n < 0         
void Dots::set(int n)
{
    if(n < 0)
    {
        s="";
    }
    for(int i=0; i<n; i++)
    {
        s+=".";
    }

};  
// postincrement (add one more dot)           
Dots Dots::operator++(int dummy)
{
    s+=".";
    return *this;
};  
// preincrement (add one more dot)
Dots &Dots::operator++()
{
    s+=".";
    return *this;
};  
// multiply # of dots by k, when k >=0

// s = .. (2)
// k = 4 
// 2 * 4 = 8
// 8 - 2 = 6
Dots &Dots::operator*=(int k)
{
    if(k >= 0)
    {
        int len = s.length();
        int product = len * k;
        for(int i=0; i<product-len; i++)
        {
            s+=".";
        }
        return *this;
    }
};     
// Dots operator*(int k) const; // like *=,  but don't modify *this.
// void print(ostream &out, bool endline = false)

int main()
{
    return 0;
}