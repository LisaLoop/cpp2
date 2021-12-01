//
// lab4.cpp
//
// CS15
// Lisa Lehrman, Elias Sosa
// 10/01/2021
//
// A program that makes sprials and prints them to an output file
/*
An int * is not an int **. Don't confuse them.
An int ** would work if (and only if) you were using ragged arrays of ints.
But then you can't then mimic the indexing into the array yourself as though the array was 2-dimensonal.
The spec said to pass the bases in as int *, not as int **.


int arr [10][5]

int * arr[5]

int ** arr

*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// countDigits is a helper function that counts
// the number of digits in a given int
int countDigits(int result)
{
    int count = 0;
    while (result != 0)
    {
        result = result / 10;
        count++;
    }
    return count;
}

// printSpiral takes a 2D matrix, a number of rows and a number of columns
// and an output file handle. It prints the spiral to the output file.
void printSpiral(ofstream &outputFile, int **arr, int rows, int cols)
{
    int result = rows * cols;
    int size = countDigits(result) + 1;
    int *ptr = &arr[0][0];

    outputFile << "-------------------------" << '\n';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            outputFile << setw(size) << *(ptr + (cols * i) + j) << '\t';
        }
        outputFile << endl;
    }
    outputFile << "-------------------------" << '\n';
}

// clearArray takes a 2D matrix, a number of rows and columns,
// It sets all elements of the array to zero.
void clearArray(int **matrix, int nRows, int nCols)
{
    int *mPtr = &matrix[0][0];
    for (int i = 0; i < nRows; i++) // for each row
    {
        for (int j = 0; j < nCols; j++) // for each column
        {
            *(mPtr + (nCols * i) + j) = 0;
        }
    }
}


/*
const matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

const matrix = [
     1,  2,  3,  4,  5,  6,  7,
     8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21,
    22, 23, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 34, 35,
    36, 37, 38, 39, 40, 41, 42,
    43, 44, 45, 46, 47, 48, 49,
];

columnCount = 7;
columnStart = 0;
columnEnd = columnCount;


rowCount = 7
rowStart = 0
rowEnd = rowCount

while (!done) {
    x = columnStart;
    y = rowStart;
    while (y < rowEnd) {
        index = (y * columnCount) + x;
        y += 1;
    }
    x += 1;
    rowStart += 1;
    rowEnd -= 1;
}

*/
// makeSpiral takes a 2D array and the number of rows and
// number of columns. It arranges the numbers to later 
// print them in a counter-clockwise spiral pattern
// void makeSpiral( int *p, int nRows, int nCols )
void makeSpiral(int * matrix, int nrows, int ncols)
{
// total number of spaces to fill the spiral
    int area = nrows * ncols; 
// counter to fill the spiral with numbers
    int counter = 0;
    int x = ncols;
    int y = nrows;
    int* ptr;
    ptr = &matrix[0];
    int intSize = 4;
    
    while(counter < area)
    {
 // down (y)
 // increment row
        while(  > nrows )
        {
            // change direction

            // increment counter
        }
 


    }
 // right 
 // increment col

 // up 
 // decrement row

 // left 
 // decrement col

}

int main(int argc, char *argv[])
{
    ofstream outputFile;
    if (argc < 2)
    {
        cout << "Usage: " << argv[0] << " <outputFile>" << endl;
        return 0;
    }
    char *outputFileName = argv[1];
    outputFile.open(outputFileName);
    if (!outputFile)
    {
        cout << outputFileName << " could not be opened.\n"
                                  "Please check that the file name exists.\n"
             << endl;
        return -1;
    }

    int rows = 4;
    int cols = 4;

    int arr1[1][1], arr2[2][2], arr3[3][3], arr4[4][4], arr5[5][5], arr6[4][7],
        arr7[7][4], arr8[4][8], arr9[8][4], arr10[15][20], arr11[10][10],
        arr12[7][7], arr13[8][8], arr14[11][11];

    int *arrays[14] = {&arr1[0][0], &arr2[0][0], &arr3[0][0], &arr4[0][0],
                       &arr5[0][0], &arr6[0][0], &arr7[0][0], &arr8[0][0],
                       &arr9[0][0], &arr10[0][0], &arr11[0][0], &arr12[0][0],
                       &arr13[0][0], &arr14[0][0]};

    int rowSizes[14] = {1, 2, 3, 4, 5, 4, 7, 4, 8, 15, 10, 7, 8, 11};
    int colSizes[14] = {1, 2, 3, 4, 5, 7, 4, 8, 4, 20, 10, 7, 8, 11};

    for (int i = 0; i < 14; i++)
    {
        clearArray(&arrays[i], rowSizes[i], colSizes[i]);
        makeSpiral(&arrays[i], rowSizes[i], colSizes[i]);
        printSpiral(outputFile, &arrays[i], rowSizes[i], colSizes[i]);
    }

    outputFile.close();
    return 0;
}
