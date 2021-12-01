//
//  main.cpp
//  assignment-4
//
//  Created by Lisa Lehrman 
//  10/19/21
//  A program that attempts to meet the spec
//  to write a Rational number calculator 

#include <iostream>
#include <fstream>
using namespace std;

#include "rational.h"

int main(int argc, const char *argv[])
{

    ifstream inputFile;
    ofstream outputFile;

    if (argc < 3)
    {
        cout << "Usage:" << argv[0] << " <input> <output>\n";

        return 0;
    }
    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];

    inputFile.open(inputFileName);
    outputFile.open(outputFileName);
    if (!inputFile)
    {
        cout << inputFileName << " could not be opened.\n"
                                 "Please check that the file name exists\n"
                                 "and it has appropriate permissions\n"
             << endl;
        return -1;
    }
    if (!outputFile)
    {
        cout << outputFileName << " file could not be opened.\n"
                                  "Please check that the file name exists\n"
                                  "and it has appropriate permissions\n"
             << endl;
        return -1;
    }

    while (!inputFile.eof())
    {

        Rational rational;
        rational.read(inputFile);
        // This is a hard coded result for meanwhile
        // until we write the calculator functions
        Rational result(1, 2);
        if (inputFile.fail())
        {
            break;
        }
        char op;
        Rational rational2;
        inputFile >> op;
        rational2.read(inputFile);
        rational.write(outputFile);
        outputFile << ' ' << op << ' ';
        rational2.write(outputFile);
        outputFile << ' ' << '=' << ' ';
        result.write(outputFile);
        outputFile << endl;
    };
    
    inputFile.close();
    outputFile.close();
    return 0;
}
