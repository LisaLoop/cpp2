#include<iostream>
using namespace std;

// int* makeArray(int length, int value)
// {
//     int arr[length];
//     for(int i=0; i<length; i++)
//     {
//         arr[i] = value;
//     }
//     return arr;
// };

int** make2DArray(int size, int value)
{
    int** arr2D = new int * [size];
    for(int i=0; i<size; i++)
    {
        arr2D[i] = new int[size];
        for(int j=0; j< size; j++)
        {
            arr2D[i][j] = value;
        }
    }

    return arr2D;
}

int *** make3DArray (int size, int value)
{
  int *** arr3D = new int ** [size];
  for(int i=0; i<size; i++)
  {
      arr3D[i] = new int*[size];
      for(int j=0; j<size; j++)
      {
          arr3D[i][j] = new int[size];
          for(int k=0; k<size; k++)
          {
              arr3D[i][j][k] = value;
          }
      }
  }
  return arr3D;
}

int main()
{
    int *** arr3D = make3DArray(5, 0);
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<5; k++)
            {
                cout << arr3D[i][j][k];
            }
          cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    return 0;
};
