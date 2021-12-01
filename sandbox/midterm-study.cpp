#include <iostream>
#include <fstream>

using namespace std;

// access array using []

// The  memcpy()  function  copies  n  bytes from memory area src(s2) to memory area dest(s1).
// The memory areas must not
// overlap.  Use memmove(3) if the memory areas do overlap.

void *memcpy(void *s1, const void *s2, size_t n)
{
    unsigned char *s3 = (unsigned char *)s1;
    unsigned char *s4 = (unsigned char *)s2;
    size_t i;

    if (s1 == s2 || !n)
        return (s1);
    for (i = 0; i < n; i++)
    {
        s3[i] = s4[i];
    }
    return (s1);
}

// strcpy with bracket bracket notation
char *strcpy1(char t[], char s[])
{
    int i = 0;

    while (t[i] = s[i])
    {
        i++;
    }
    return t;
}

// direct pointer notation
char *strcpy2(char *s1, char *s2)
{
    char *t = s1;
    char *s = s2;

    while (*s) 
    {
        *t = *s;
        t++;
        s++;
    }
    *t = '\0';
    return s1;
}

char *strcpy2variant(char *t, char *s)
{
    char *ptr = t;
    while (*t++ = *s++);
    return ptr;
}

// base + offset
char *strcpy3(char *dest, const char *src)
{
    int i = 0;

    if (dest == src)
        return dest;
    while ((*(dest + i) = *(src + i)))
    {
        i++;
    }
    return dest;
}
// bracket notation
int strcmp(char s[], char t[])
{
    int i = 0;
    while(s[i] && s[i] == t[i])
    {
        i++;
    }
    return s[i] - t[i];
}

// base + offset 
int strcmp(char *s, char* t)
{
    int i=0;
    while(*(s+i) && *(s+i) == *(t+i))
    {
        i++;
    }
    return *(s+i) - *(t+i);
}

// direct pointer notation 
int my_strcmp(char *strg1, char *strg2)
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )
    {
        strg1++;
        strg2++;
    }

    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }

    else
    {
        return *strg1 - *strg2;
    }
}


// base memory of address of array (2d or 3d or 1d);
// pointer to an integer (pass by reference);
//

// int a[][2] = {{1,2},{3,4}}; a 2d array treated as 1-d array
//  1 2 3 row o
//  4 5 6 row 1
//  7 8 9 row 2         2 and 3 are next to each other;
// 1 2 3 4 5 6 7 8 9
// 
//  *(mPtr + (nCols * i) + j) = 0;
//
// lets say we want to get value of 5
// get value of 5
// a[4] or *(a + 4);
// get value of 5
// *(a + ( 3 * 1) + 1);
// *(a + ( 3 * 1) + 2); (3 * i ) go to the row, j index inside the row;

// b      col1   col2
// row 0: 1      2          cols of b : 2            
// row 1: 3      4          rows of a = 4;
// row 2: 5      6
// row 3: 7      8

// how many element in a row(row length)?

// 2

// how many cols in this 2d array?

// 2

// ---> # of element in a row = cols in this array.

// b: 1  2  3  4  5  6  7   8
// b:       |     |     |   
// 
//
//          2
// *(a + ( ncol * i) + j );

// base + (row length * rows to skip) + columns to skip

///

// char a[4];
// int b[5];
// 
// a:
// 1 byte
// 00000000 00000000 00000000 00000000
// a
// a+1
// a + 1; skip 1 byte;
// b + 1; skip 4 bytes;
//  
//
// b:   1 bytes  2 byte   3 byte   4 byte
//     b[0]:00000000 00000000 00000000 00000000
// b
//     b[1]: 00000000 00000000 00000000 00000000
//     b + 1
//     00000000 00000000 00000000 00000000
//     00000000 00000000 00000000 00000000
//      
// get value of 3
// *(a + (4 * 1) ) + 2 equals *(a + 6);

// get value of 5
// a[4] or *(a + 4);
// get value of 5
// *(a + ( 3 * 1) + 1) = *( a + 4 );

// 

// a point to 1, address of 1(base element)
// how do we get 2?
// 
// int foo (int *a)
// {

// }

// foo(&a[0][0])
// foo(&5)

int main(int argc, char **argv)
{   
    // memcpy usage
    // int a[3] = {1,2,3};
    // int b[3] = {4,5,6};

    // memcpy( a, b, sizeof(b) );
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << a[i] << endl;
    // }

    // strcpy test

    // size of s1 has to be bigger than s2 to use strcpy, so it will not be out of bound.
    // when using strpcy.
    // char s1[100] = "apple", s2[] = "teacher";
    // cout << "strcpy1" << endl;
    // cout << strcpy1(s1, s2) << endl;
    // cout << "---------------------------------------" << endl;
    // cout << "strcpy2" << endl;
    // cout << strcpy2(s1, s2) << endl;
    // cout << strcpy2variant(s1, s2) << endl;
    // cout << "---------------------------------------" << endl;
    // cout << "strcpy3" << endl;
    // cout << strcpy3(s1, s2) << endl;;
    
    return 0;
}