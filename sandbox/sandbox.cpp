#include <iostream>
using namespace std;
// & - address operator
// * - dereferencing operator

int main()
{
    int num = 5;
    
    int *x = &num; // the only thing it can contain is an address
    int whatever = *x; //(dereferences the value (refer to the value -- get the value))

    num = 10;
    // cout << "num" << endl;
    // cout << num << endl; // 5
    // cout << &num << endl; // address

    cout << "x" << endl;
    cout << x << endl; // address
    cout << *x << endl; // 10
    // & is the address of the pointer
    // the pointer itself is a value in memory.

    cout << "whatever" << endl;
    cout << whatever << endl; // 5
    // cout << &whatever << endl; // 
    return 0;
}