//
// quadratic.cpp
//
// Lisa Lehrman
// 09/05/2021
// CS15
// A program to read the coefficients of a series of quadratic equations
// from a text file and print the associated roots
// or error messages to another text file.

#include <iostream>
#include <fstream>
using namespace std;

int readLineFromFile(float &a, float &b, float &c, ifstream &inputFile)
{
    bool rA = inputFile >> a;
    bool rB = inputFile >> b;
    if (!rA || !rB)
    {
        return -1;
    }
    bool rC = inputFile >> c;

    return 0;
}

int calculateRoots(float a, float b, float c, float &root1, float &root2)
{
    // The discriminant is the part of the quadratic formula under the square
    // root.
    float discriminant = (b * b) - (4 * a * c);
    float discriminantRoot = sqrt(discriminant);
    float denominator = 2 * a;
    if (a == 0)
    {
        return -1;
    }
    if (discriminant < 0)
    {
        return -2;
    }

    root1 = (-(b)-discriminantRoot) / denominator;
    root2 = (-(b) + discriminantRoot) / denominator;
    return 0;
}

void printRow(float a, float b, float c, float root1, float root2, int code,
              ofstream &outputFile)
{
    string message;
    int width = 10;
    static bool isFirstTime = true;

    if (isFirstTime)
    {
        outputFile << setw(width) << "a" << setw(width) << "b" << setw(width)
                   << "c" << setw(width) << "root 1" << setw(width) << "root 2"
                   << setw(width * 2) << "message" << endl;
        outputFile
            << "-----------------------------------"
            << "-----------------------------------"
            << endl;
        isFirstTime = false;
    }
    if (code < 0)
    {
        if (code == -1)
        {
            message = "No solution";
        }
        if (code == -2)
        {
            message = "Complex roots";
        }
        if (code == -3)
        {
            message = "Data error on input";
        }
        outputFile << setw(width) << a << setw(width) << b << setw(width) << c
                   << setw(width * 2) << "" << setw(width * 2) << message
                   << endl;
    }
    else
    {
        outputFile << setw(width) << a << setw(width) << b << setw(width) << c
                   << setw(width) << root1 << setw(width) << root2 << endl;
    }
}

int main()
{
    float a, b, c;
    float root1, root2;
    ofstream outputFile;
    ifstream inputFile;
    string inputFileName, outputFileName;

    cout << "Please enter the input file name with the extention: " << endl;
    cin >> inputFileName;
    cout << "Please enter the output file name with the extention: " << endl;
    cin >> outputFileName;

    inputFile.open(inputFileName);
    outputFile.open(outputFileName);

    if (!inputFile || !outputFile)
    {
        cout << "Something went wrong!" << endl;
        return -1;
    }

    outputFile << inputFileName << " " << outputFileName << endl;
    bool readError = false;
    while (!readError)
    {
        readError = readLineFromFile(a, b, c, inputFile) < 0;
        if (!readError)
        {
            int code = calculateRoots(a, b, c, root1, root2);
            printRow(a, b, c, root1, root2, code, outputFile);
        }
        else
        {
            printRow(0, 0, 0, 0, 0, -3, outputFile);
        }
    }

    inputFile.close();
    outputFile.close();
    return 0;
}