#include <iostream>
using namespace std;

int mystery(int a, int b)
{
    int c = a + b;
    b = a + c;
    a += c + b;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    return a + b + c;
}

int mystery2(int &a, int b)
{
    int c = a + b;
    b = a + c;
    a += c + b;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    return a + b + c;
}

int mystery3(int a, int &b)
{
    int c = a + b;
    b = a + c;
    a += c + b;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    return a + b + c;
}

int mystery4(int &a, int &b)
{
    int c = a + b;
    b = a + c;
    a += c + b;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    return a + b + c;
}

int main()
{
    int a = 2, b = 5, c;
    c = mystery(b, a);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    b = mystery(a, c);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    cout << "\n" << "\n";
    a = 2, b = 5; c = 0;
    c = mystery2(b, a);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    b = mystery2(a, c);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    cout << "\n" << "\n";
    a = 2, b = 5, c = 0;
    c = mystery3(b, a);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    b = mystery3(a, c);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    cout << "\n" << "\n";
    a = 2, b = 5, c = 0;
    c = mystery4(b, a);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    b = mystery4(a, c);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    return 0;
}