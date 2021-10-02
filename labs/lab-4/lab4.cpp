#include <iostream>
#include <fstream>
using namespace std;
// lab 4

// makeSpiral(int *p, int nRows, int nCols ) 
// printSpiral(int *p, int nRows, int nCols, ofstream output)


void clearArray(int *arr[], int nrows, int ncols)
{
    for(int i =0; i < nrows; i++)
    {
        for(int j=0; j<ncols; j++)
        {
            arr[i][j] = 0;
            cout << arr[i][j] << endl; 
        }
    }
    
}

int main(int argc, char* argv[])
{

    int rows;
    int cols;
    int arr1[1][1], arr2[2][2], arr3[3][3], arr4[4][4];
    int *arrays[4] = {&arr1[0][0], &arr2[0][0], &arr3[0][0], &arr4[0][0]};
    clearArray(&arrays[1], 2,2);
    // clearArray(arr2, 2,2);
    // clearArray(arr3,3,3);
    // clearArray(arr4,4,4);
    return 0;
}

