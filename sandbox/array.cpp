//
// array_pointer.cpp
//
// Keith Mehl
// 8/26/13
// CSCI-15 example program
// Illustrate some features of arrays and pointers -- the pairs of functions
// sort1() and exchange1(), and sort2() and exchange2() are roughly identical
// (there is a tiny difference, but it does not affect this program)
//

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstdlib> // for system()
const int SIZE = 10;

// exchange() using references
void exchange1( int &a, int &b )
{
    int t = a;
    a = b;
    b = t;
    return;
}

// very simple sort (ripple sort)
void sort1( int a[], int n )
{
    int i, j;
    cout << "In sort1(), array size is " << sizeof(a) << endl;
    for( i = 0; i < n-1; i++ )
    {
        for( j = i+1; j < n; j++ )
        {
            if( a[i] > a[j] )
            {
                exchange1( a[i], a[j] );
            }
        }
    }
    return;
}

// exchange() using pointers
void exchange2( int *a, int *b )
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

// same sort, using various types of pointer notation
void sort2( int *a, int n )
{
    int i, j;
    cout << "In sort2(), array size is " << sizeof(a) << endl;
    for( i = 0; i < n-1; i++ )
    {
        for( j = i+1; j < n; j++ )
        {
            // illustrate base + offset and indexing to access elements
            // the compiler handles the sizes of the elements itself
            // base + offset needs () because * has higher precedence than +
            if( *(a+i) > a[j] )
            {
                // a pointer (the base a) + an offset i (an int)
                // yields a pointer
                // or you can take the address of the element a[i]
                exchange2( a+i, &a[j] );  // &a[j] becomes &(*(a+j))
            }
        }
    }
    return;
}

// simple print routine, assumes n >= 1 and data will fit on a line
void printIt( int a[], int n )
{
    int i;
    cout << a[0];
    for( i = 1; i < n; i++ )
    {
        cout << '\t' << a[i];
    }
    cout << endl;
    return;
}

int main()
{
    // two identical data arrays
    int a1[SIZE] = { 5, 1, 2, 9, 0, 3, 8, 7, 4, 6 },
        a2[]     = { 5, 1, 2, 9, 0, 3, 8, 7, 4, 6 }; // size from initializer
    cout << "In main(), a1 size is " << sizeof(a1) << endl;
    printIt( a1, SIZE );
    sort1( a1, SIZE );
    printIt( a1, SIZE );
    system( "pause" ); // stop and run system command 'pause', then resume
    cout << "In main(), a2 size is " << sizeof(a2) << endl;
    printIt( a2, SIZE );
    sort2( a2, SIZE );
    printIt( a2, SIZE );
    return 0;
}
