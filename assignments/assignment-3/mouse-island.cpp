// mouse-island.cpp
// Lisa Lehrman
// Oct 1, 2021
// CS15
// Assignment 3
// A program that does something
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
/*

parse command line parameters, open files ✅
if needed, seed the random number generator ✅
read the map (same syntax as print array matrix[x][y] = thingy)
&& save initial positions of the mouse and bridges
initialize the count map to all zeros
print the file names, seed rule, island map
loop over 100 lives
 put mouse at starting point on map
 loop until 100 moves made, or mouse escapes or drowns
 move mouse
 count move to target square
 if( drowned )
 handle drowning
 else if( escaped )
 handle escaping
 end if
 end loop until 100 moves, etc.
 if( starved )
 handle starving
 end if
end loop over 100 lives
print life statistics and count map
close files

Read the island’s map
directly from the file using an ifstream. The file's first 2 values are the number of rows and columns in
the map. The rest of the data looks like this:
-1 – water
0 – land
1 – initial position of the mouse
Second why can't you just loop through the data
that you have and put it in each column?
*/
struct Vec2 {
    int x;
    int y;
};
/*
parseFirstLine is a helper function that takes a char* header and two longs as
reference parameters that represent rows and columns. It will assign values to
the rows and columns variables.
*/
void parseFirstLine(char *header, long &rows, long &cols)
{
    char *pEnd;
    rows = strtol(header, &pEnd, 10);
    cols = strtol(pEnd, NULL, 0);
}

/*
parseHeader is the function responsible for handling the first line of the
input file, which is expected to contain the values for rows and cols. It takes
an input file handle, and two longs representing rows and cols as reference
paramters.
*/
void parseHeader(ifstream &inputFile, long &mapRows, long &mapCols)
{
    char line[21];
    while (!inputFile.eof())
    {
        int size = sizeof(line);
        inputFile.getline(line, size);
        parseFirstLine(line, mapRows, mapCols);
        break;
    }
    // cout << "mapRows: " << mapRows << " mapCols: " << mapCols << endl;
}

void parseLine(int **matrix, char *line, int currentRow, long cols)
{
    const int numericBase = 10;
    char *pEnd;
    long int n = strtol(line, &pEnd, numericBase);
    // todo: better long to int conversion
    matrix[currentRow][0] = (int)n;
    for (int i = 1; i < cols; i++)
    {
        long int n = strtol(pEnd, &pEnd, numericBase);
        // cout << "n: " << n << endl;
        matrix[currentRow][i] = (int)n;
    }
}

void parseMap(ifstream &inputFile, int **matrix, long mapRows, long mapCols)
{
    int row = 0;
    string line;
    while (getline(inputFile, line))
    {
        char *cLine = new char[line.size() + 1];
        // replace with strcpy
        copy(line.begin(), line.end(), cLine);
        // use sizeof
        cLine[line.size()] = '\0';
        parseLine(matrix, cLine, row, mapCols);
        row++;
    }
}

void printArray(int **matrix, int nRows, int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }
}
// 

 Vec2 getMousePosition(int **matrix, int nRows, int nCols)
{
    Vec2 mousePosition;
    mousePosition.x = -1;
    mousePosition.y = -1;
    int mouse = 1;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
             if(matrix[i][j] == mouse)
             {
                 mousePosition.x = j;
                 mousePosition.y = i;
                return mousePosition;
             }
        }
    }
    return mousePosition;
}

int main(int argc, char *argv[])
{

    char *seed = nullptr;
    if (argc < 3 || argc > 5)
    {
        cout << "Usage: " << argv[0] << " <input> <output> [<seed>]" << endl;
        cout << "\nEnter either the seed value or the string TIME" << endl;
        cout << "in uppercase to seed the random number" << endl;
        cout << "generator using the current time." << endl;
        cout << "If no value for seed is entered, the number" << endl;
        cout << "generator will not be seeded." << endl;
        return 0;
    }
    if (argc == 4)
    {
        seed = argv[3];
        cout << "seed: " << seed << endl;
    }
    if (seed && strcmp(seed, "TIME") == 0)
    {
        srand(time(0));
        cout << "seeded with time" << endl;
    }
    else if (seed)
    {
        int s = atoi(seed);
        srand(s);
    }
    else
    {
        rand();
    }

    ifstream inputFile;
    ofstream outputFile;
    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];

    inputFile.open(inputFileName);
    outputFile.open(outputFileName);
    if (!inputFile)
    {
        cout << "There was a problem opening input file " << inputFileName << endl;
    }
    if (!outputFile)
    {
        cout << "There was a problem opening output file " << outputFileName << endl;
    }

    long mapRows, mapCols;
    // char **islandMap;
    int **mouseMoves;

    parseHeader(inputFile, mapRows, mapCols);
    // initialize container array
    int **matrix = new int *[mapRows]; 
    // initialze rows
    for (int i = 0; i < mapRows; i++)
    {
        // Declare a memory block
        // of size n
        matrix[i] = new int[mapCols];
    }
    // cout << "mapCols: " << mapCols << endl;
    parseMap(inputFile, matrix, mapRows, mapCols);
    printArray(matrix, mapRows, mapCols);
    Vec2 mousePosition = getMousePosition(matrix, mapRows, mapCols);
    cout << "x: " << mousePosition.x << "y: " << mousePosition.y << endl;
    inputFile.close();
    outputFile.close();
    return 0;
}

/*
References

On converting a string to a char
https://stackoverflow.com/questions/347949/how-to-convert-a-stdstring-to-const-char-or-char

On using the new operator to initialize a container array and
assigning declaring the rows inside of a a loop 
https://www.geeksforgeeks.org/pointers-c-examples/
*/