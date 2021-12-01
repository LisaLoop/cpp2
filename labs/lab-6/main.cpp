#include <iostream>
using namespace std;

/*
Suppose we store the contents of a six by six tic-tac-toe board using a
two-dimensional array with six rows and six columns. Implement a function getValue that
takes the 2D array as its parameter and returns 1, -1 or 0 according to whether the board
contains a win for 'X', 'O' or neither player.  (Assume that there is never a case where the
board contains wins for both 'X' and 'O'.) The prototype for getValue is below.

int getValue(char squares[][6]) ;

A win for 'X' means four adjacent X's in a line either across, down or diagonally.
You'll see there are 54 ways that can happen if you draw a six by six grid and count the
possibilities. Similarly for 'O'.

Assume that every element of the array always contains one of three values: 'X', 'O' or '-'.
(The dash represents a blank square.)

*/

int getValue(char squares[][6])
{
    int rowLength = 6;
    int colLength = 6;
    int value;
    int kernel = 4;
    // left -> right
    for (int row = 0; row < rowLength; row++)
    {
        for (int col = 0; col <= colLength - kernel; col++)
        {
            char a = squares[row][col];    
            char b = squares[row][col + 1];
            char c = squares[row][col + 2];
            char d = squares[row][col + 3];
    
            if (a == b && b == c && c == d)
            {
                if (a == 'X')
                {
                    // X wins
                    return 1;
                }
                if (a == 'O')
                {
                    // O wins
                    return -1;
                }
            }
        }
    }

    // up -> down
    for (int row = 0; row <= rowLength-kernel; row++)
    {
        for(int col=0; col < colLength; col++)
        {
            char a = squares[row][col];
            char b = squares[row+1][col];
            char c = squares[row+2][col];
            char d = squares[row+3][col];
            if(a == b && b == c && c == d)
            {
                if(a == 'X')
                {
                    // X wins 
                    return 1;
                }
                if(a == 'O')
                {
                    // O wins 
                    return -1;
                }
            }
            
        }
    }
    
    // diagonal down -> right
    for(int row=0; row <= rowLength-kernel; row++)
    {
        for(int col=0; col <= colLength-kernel; col++)
        {
            char a = squares[row][col];
            char b = squares[row+1][col+1];
            char c = squares[row+2][col+2];
            char d = squares[row+3][col+3];
            if(a == b && b == c && c == d)
            {
                if(a == 'X')
                {
                    return 1;
                }
                if(a == 'O')
                {
                    return -1;
                }
            }

        }
    }

    // diagonal down -> left
    for(int row=0; row <= rowLength-kernel ;row++)
    {
        for(int col=kernel-1; col < colLength; col++)
        {
            char a = squares[row][col];
            char b = squares[row+1][col-1];
            char c = squares[row+2][col-2];
            char d = squares[row+3][col-3];
            if(a == b && b == c && c == d )
            {
                if(a == 'X')
                {
                    return 1;
                }
                if(a == 'O')
                {
                    return -1;
                }
            }
        }
    }
    return 0;
};

int main()
{
    char squares[][6] = {{'X', 'X', 'O', 'X', 'X', 'O'},
                         {'O', 'X', 'O', 'O', 'O', 'X'},
                         {'O', '-', '-', '-', 'X', 'O'},
                         {'X', '-', 'O', '-', 'O', '-'},
                         {'X', '-', 'X', '-', '-', '-'},
                         {'O', 'X', 'O', '-', '-', '-'}};


    cout << getValue(squares) << endl;
    return 0;
}