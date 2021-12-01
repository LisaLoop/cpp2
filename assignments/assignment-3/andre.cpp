//
// Assignment03.cpp
// Carlo Garate
// 10/03
// CS15 Assignment03
// ????
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void readFile(ifstream &infile, int array2D[][20], int numR, int numC, int &counter)
{
    for (int i = 0; i < numC; i++)
    {
        infile >> array2D[counter][i];
    }
    counter++;
};
void saveMouse(int array2D[][20], int mrows, int mcolumns, int mousePos[])
{
    for (int i = 0; i < mrows; i++)
    {
        for (int j = 0; j < mcolumns; j++)
        {
            if (array2D[i][j] == 1)
            {
                mousePos[0] = i;
                mousePos[1] = j;
                array2D[i][j] = 0;
            }
        }
    }
};
void moveMouse(int mouse[])
{
    int random = rand() % 4;
    static const int movement[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    mouse[0] += movement[random][0];
    mouse[1] += movement[random][1];
};
void printStatistics2(ofstream &outfile, int result)
{
    if (result == -1)
    {
        outfile << "The mouse has drowned!" << endl;
    }
    else if (result == 0)
    {
        outfile << "The mouse has escaped!" << endl;
    }
    else if (result == 1)
    {
        outfile << "The mouse has starved to death!" << endl;
    }
};
void checkingMouse(int array2D[][20], int mousePos[], int &starve, int &alive, int &drown, int rows, int columns, int map2[][20], ofstream &outfile)
{
    int movements = 0, state;
    while (movements < 100)
    {
        moveMouse(mousePos);
        map2[mousePos[0]][mousePos[1]]++;
        if (array2D[mousePos[0]][mousePos[1]] == -1)
        {
            state = -1;
            printStatistics2(outfile, state);
            drown++;
            return;
        }
        else if (mousePos[0] == rows - 1 || mousePos[1] == columns - 1)
        {
            state = 0;
            printStatistics2(outfile, state);
            alive++;
            return;
        }
        movements++;
    }
    if (movements == 100)
    {
        state = 1;
        printStatistics2(outfile, state);
        starve++;
        return;
    }
};
void printStatistics1(char *inputName, char *outputName, int method_counter, ofstream &outfile)
{
    outfile << "Input file name: " << inputName << endl;
    outfile << "Output file name: " << outputName << endl;
    outfile << "Rule of seeding: ";
    if (method_counter == 0)
    {
        outfile << "Without seeding." << endl;
    }
    else if (method_counter == 1)
    {
        outfile << "Seeding with a fixed value." << endl;
    }
    else
    {
        outfile << "Seeding with the system time." << endl;
    }
    outfile << endl;
};
int biggestValue(int map2[][20], int rows, int columns)
{
    int biggest = map2[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (biggest < map2[i][j])
            {
                biggest = map2[i][j];
            }
        }
    }
    return biggest;
};
void printStatistics3(ofstream &outfile, int map2[][20], int map[][20], int rows, int columns, int starve, int escape, int drown)
{
    int big = biggestValue(map2, rows, columns), counter = 0;
    while (big)
    {
        big = big/10;
        counter++;
    }
    outfile << "Number of times that the mouse has drowned: " << drown << endl;
    outfile << "Number of times that the mouse has starved to death: " << starve << endl;
    outfile << "Number of times that the mouse has escaped: " << escape << endl;
    outfile << "Original map: " << endl;
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < columns; y++)
        {
            outfile << setw(counter) << map[x][y] << " ";
        }
        outfile << endl;
    }
    outfile << "Counts of mouse movement map: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            outfile << setw(counter) << map2[i][j] << " ";
        }
        outfile << endl;
    }
    outfile << "-------------------------------------------------------------" << endl;
}

int main(int argc, char *argv[])
{
    ifstream infile;
    ofstream outfile;
    int rows, columns, countRows = 0, map[20][20] = {2}, map2[20][20] = {0}, mouse[2] = {0, 0}, originalMouse[2] = {0, 0}, seed, starve_count = 0, alive_count = 0, drown_count = 0, method = 0, livesCounter = 0;
    if (argc < 4)
    {
        cout << "You forgot to write down the input file, output file or the seed for the random number. Please, try again." << endl;
    }
    else
    {
        char *inputfile = argv[1], *outputfile = argv[2];
        infile.open(inputfile);
        outfile.open(outputfile);
        if (!infile)
        {
            cout << "There was an error with your input. Please, try again." << endl;
        }
        else
        {
            cout << "File opened succesfully!" << endl;
            infile >> rows;
            infile >> columns;
            while (infile)
            {
                readFile(infile, map, rows, columns, countRows);
            }
            while (method < 3)
            {
                printStatistics1(inputfile, outputfile, method, outfile);
                seed = atol(argv[3]);
                if (method == 1)
                {
                    srand(seed);
                    cout << seed << endl;
                }
                else if (method == 2)
                {
                    srand(time(NULL));
                }
                saveMouse(map, rows, columns, mouse);
                originalMouse[0] = mouse[0];
                originalMouse[1] = mouse[1];
                while (livesCounter < 100)
                {
                    checkingMouse(map, mouse, starve_count, alive_count, drown_count, rows, columns, map2, outfile);
                    mouse[0] = originalMouse[0];
                    mouse[1] = originalMouse[1];
                    livesCounter++;
                }
                printStatistics3(outfile, map2, map, rows, columns, starve_count, alive_count, drown_count);
                for (int m = 0; m < rows; m++)
                {
                    for (int n = 0; n < columns; n++)
                    {
                        map2[m][n] = 0;
                    }
                }
                mouse[0] = originalMouse[0];
                mouse[1] = originalMouse[1];
                starve_count = 0;
                alive_count = 0;
                drown_count = 0;
                livesCounter = 0;
                method++;
            }
            cout << "method: " << method << endl;
         }    
        infile.close();
        outfile.close();
    }
    return 0;
}