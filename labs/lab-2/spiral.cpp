/*
spiral.cpp

Lisa Lehrman, Alex Ho
9/8/21
CS15 
Lab 2
The program reads a series of corner sizes and prints 
a spiral of those dimensions to an output file. 

*/


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int WIDTH = 15;
const int HEIGHT = 20;

// clearArray takes a 2D array, a number of rows and columns,
// It sets all elements of the array to zero.
void clearArray(int arr[][WIDTH], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = 0;
        }
    }
}
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
// printSpiral takes a 2D array, a number of rows and a number of columns
// and an output file handle. It prints the spiral to the output file. 
void printSpiral(int arr[][WIDTH], int rows, int cols, ofstream &outputFile)
{
    int result = rows * cols;
    int size = countDigits(result) + 1;

    outputFile << "-------------------------" << '\n';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            outputFile << setw(size) << arr[i][j]; //
        }
        outputFile << endl;
    }
    outputFile << "-------------------------" << '\n';
}
// makeSpiral takes a 2D array and the number of rows and
// number of columns.
// The function will fill the rows-by-columns corner of
// the array with the integers from 1 to (rows * columns)
// in a counter-clockwise spiral pattern
void makeSpiral(int arr[][WIDTH], int rows, int cols)
{
    int counter = 1;
    int finish = rows * cols;
    int x = 0; // col
    int y = 0; // row
    int width = cols;
    int height = rows;
    int minX = 1; // don't want to override the first column
    int minY = 0; // all the way to the top
    while (counter < finish)
    {
        // down - increment y
        for (; y < height - 1; y++)
        {
            arr[y][x] = counter;
            counter++;
        }
        height--;
        // right - increment x
        for (; x < width - 1; x++)
        {
            arr[y][x] = counter;
            counter++;
        }
        width--;
        // up - decrement y
        for (; y > minY; y--)
        {
            arr[y][x] = counter;
            counter++;
        }
        minY++;
        // left - decrement x
        for (; x > minX; x--)
        {
            arr[y][x] = counter;
            counter++;
        }
        minX++;
    }
    arr[y][x] = finish;
}

int main()
{
    ofstream outputFile;
    outputFile.open("FinishProduct");
    if (!outputFile)
    {
        cout << "The file failed to open." << endl;
        return -1;
    }
    const int CORNERSIZE_LENGTH = 15;
    int cornerSizes[][2] = {
        {1, 1}, {1, 2}, {2, 1}, 
        {2, 2}, {3, 3}, {4, 4},
        {5, 5}, {4, 7}, {7, 4},
        {4, 8}, {6, 4}, {15, 14},
        {5, 6}, {19, 5}, {4, 14}};

    const int rows = WIDTH;
    const int cols = HEIGHT;
    int arr[HEIGHT][WIDTH];

    int count = 0;
    while (count <= CORNERSIZE_LENGTH - 1)
    {
        clearArray(arr, cornerSizes[count][0], cornerSizes[count][1]);
        makeSpiral(arr, cornerSizes[count][0], cornerSizes[count][1]);
        printSpiral(arr, cornerSizes[count][0], cornerSizes[count][1], 
        outputFile);
        count++;
    }
    return 0;
}