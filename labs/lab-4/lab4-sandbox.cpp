#include <iostream>
using namespace std;

void clearArray(int *p[], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p[i][j] = 0;
            // cout << p[i][j] << endl;
        }
    }
}


/*
mPtr = &matrix[0][0];       // get base of matrix
    while( mPtr < ( &matrix[0][0] ) + 12 ) // + 12 is
     cout << setw( 6 ) << *mPtr++;
*/
void makeSpiral(int** p, int rows, int cols)
{
    int* mPrt = &p[0][0];
    while(mPrt < (&p[0][0]) + rows)
    {
        
        // cout << *(mPtr + (rows * ))
        
    }
}
int main()
{
    int arr1[1][1];
    int arr2[2][3];
    int arr3[4][4];
    // int* p is an array that contains the bases of other 2d arrays
    // need & and [][] to get the base
    int* p[3] = {&arr1[0][0], &arr2[0][0], &arr3[0][0]};
    clearArray(&p[0], 1, 1);
    makeSpiral(&p[0], 1, 1);
    return 0;
}