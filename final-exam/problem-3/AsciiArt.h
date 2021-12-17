#ifndef ASCIIART_H
#define ASCIIART_H
#include <iostream>
using namespace std;


class AsciiArt {
    friend ostream& operator<<(ostream& out, const AsciiArt& a); // Call a.draw(). 
private:
    int numRows, numCols;
    char** grid;  // A 2D array to hold the characters

    // optional helper functions
    static char** makeGrid(int numRows, int numCols); // dynamically allocate a 2D array

    static void deleteGrid(char** g, int numRows);  // delete g[0] etc. and delete g.

    static void copyGrid(char**dest, char**source, int numRows, int numCols); // copy data

    

public:

    AsciiArt(int numR, int numC); // Set numRows to max(1,numR), numCols to max(1,numC)
    AsciiArt(const AsciiArt& other);  // copy constructor. Make sure to do a deep copy.
    AsciiArt& operator=(const AsciiArt& other); // Overloaded assignment operator. Get it right!

    AsciiArt& operator*=(int mult); // enlarge, e.g. mult=2 --> "double" each row & column (See output)
    AsciiArt& operator/=(int div); // reduce e.g. div=2 --> keep every other row & columm. (See output)
    AsciiArt operator*(int mult); // Call *=
    AsciiArt operator/(int div); //  Call /=
    ~AsciiArt(); // destructor (Call deleteGrid if you implemented it.)


    // return true if the *this and other have the same dimensions and the same characters
    // return false otherwise
    bool operator==(const AsciiArt& other);

    bool operator!=(const AsciiArt& other);  // call operator==

    // Set grid[row][col] to c or do nothing if row or col is out of bounds.
    void setChar(int row, int col, char c);

    // return grid[row][col] or return '\0' if row or col is out of bounds.
    char getChar(int row, int col) const;


    // draw the picture to out.  See sample output as a guide.
    void draw(std::ostream& out) const;

    // If row or startCol is out-of-bounds then return without copying anything.
    // Otherwise, copy s[0] into grid[row][startCol], s[1] into grid[row][startCol+1] etc. 
    // If s is "too long to fit", stop copying beyond grid[row][numCols-1].
    void setRow(int row, int startCol, const char s[]);


    // return numRows
    int getNumRows() const;

    // return numCols
    int getNumCols() const;

    // Flip the picture. That means swap the dimensions and  
    // set each grid[j][i] in the new picture to grid[i][j] from the old picture.
    // Avoid memory leaks. Return *this.
    AsciiArt& flip();
};

#endif