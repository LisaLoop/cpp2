#include <iostream>
using namespace std;

char *** elCastillo(int levels);
void print1DArray (char *array, int size) ;
void print2DArray(char ** array, int rows) ;
void print3DArray(char *** array, int numLevels) ;


int main() {
    print3DArray(elCastillo(10), 10);
    cout << endl;
    return 0;
}

char *** elCastillo(int levels)
{
    int ASCII_A = 65;
    char ***tower = new char **[levels];
    for(int grid=0; grid<levels; grid++)
    {
        tower[grid] = new char* [grid+1];
        for(int row=0; row<grid+1; row++)
        {
            tower[grid][row] = new char[grid+1];
            for(int column=0; column<grid+1; column++)
            {
                tower[grid][row][column] = ASCII_A+grid;
            }
        }
    }

    return tower;
}

void print1DArray (char *array, int size) {
    for (int i = 0; i < size; i++) cout << array[i];
    cout << endl;
}

void print2DArray(char ** array, int rows) {
    for (int i = 0; i < rows; i++) 
    {
        print1DArray(array[i], rows);
    }
}

void print3DArray(char *** array, int numLevels) {
    for (int l = 0; l < numLevels; l++) 
       print2DArray(array[l], l+1);
    cout <<endl;
}

/*
PARTS b and c are at the bottom.

b)  Draw a picture showing how the various 1D arrays
are linked by pointers when we call elCastillo(3). 
(see attached png)

c) Give a general formula for f(n), the number of 1D arrays allocated
resulting from the call to elCastillo(n). Justify your formula. 

n = number of grids
How many rows are in the tower?

n = 1 -> 1
n = 2 -> 1 + 2
n = 3 -> 1 + 2 + 3
n = 4 -> 1 + 2 + 3 + 4

f(n) = n + f(n - 1)
*/