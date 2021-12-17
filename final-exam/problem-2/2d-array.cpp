int ** make2DArray(int rows, int columns, int initialValue)
{
    int i,j;
    int** arr = new int*[rows];
    for(i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
        for (j=0; j<columns; j++)
        {
            arr[i][j] = initialValue;
        }
    }
    return arr;
}