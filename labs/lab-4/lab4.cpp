//
// lab4.cpp
//
// CS15
// Lisa Lehrman, Elias Sosa
// 10/01/2021
//
// A program that makes sprials and prints them to an output file

#include <iostream>
#include <fstream>
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

// makeSpiral takes a 2D array and the number of rows and
// number of columns. It arranges the numbers to later 
// print them in a counter-clockwise spiral pattern
void makeSpiral(int **matrix, int nrows, int ncols)
{
    int *mptr = &matrix[0][0];
    int loop_count = 0;
    int total = nrows * ncols;
    int counter = 0;
    while (counter < total)
    {

        for (int i = 0; i < nrows; i++)
        {
            if (*(mptr + (ncols * i) + loop_count) == 0)
            {
                counter++;
                *(mptr + (ncols * i) + loop_count) = counter;
            }
        }

        for (int i = 0; i < ncols; i++)
        {
            if (*(mptr + (ncols * (nrows - 1 - loop_count)) + i) == 0)
            {
                counter++;
                *(mptr + (ncols * (nrows - 1 - loop_count)) + i) = counter;
            }
        }
        for (int i = nrows; i > -1; --i)
        {
            if (*(mptr + (ncols * i) + (ncols - 1 - loop_count)) == 0)
            {
                counter++;
                *(mptr + (ncols * i) + (ncols - 1 - loop_count)) = counter;
            }
        }
        for (int i = ncols; i > -1; --i)
        {
            if (*(mptr + (ncols * loop_count) + i) == 0)
            {
                counter++;
                *(mptr + (ncols * loop_count) + i) = counter;
            }
        }
        loop_count++;
    }
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
